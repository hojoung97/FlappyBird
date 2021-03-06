/*
 * lcd.c
 *
 *  Created on: Nov 28, 2019
 *      Author: jang88
 */
#include "lcd.h"
#include "stm32f0xx.h"
#include "stm32f0_discovery.h"
#include <stdlib.h>
#include <stdio.h>
#include "init.h"
#include <string.h>


// These are function pointers.  They can be called like functions
void (*cmd)(char b) = 0;
void (*data)(char b) = 0;
void (*display1)(const char *) = 0;
void (*display2)(const char *) = 0;

void spi_cmd(char);
void spi_data(char);

void generic_lcd_startup(void) {
    nano_wait(100000000); // Give it 100ms to initialize
    cmd(0x38);  // 0011 NF00 N=1, F=0: two lines
    cmd(0x0c);  // 0000 1DCB: display on, no cursor, no blink
    cmd(0x01);  // clear entire display
    nano_wait(6200000); // clear takes 6.2ms to complete
    cmd(0x02);  // put the cursor in the home position
    cmd(0x06);  // 0000 01IS: set display to increment
}

void spi_cmd(char b) {
    // Your code goes here.
	while((SPI2->SR & SPI_SR_TXE) == 0);
	SPI2->DR = b;
}

void spi_data(char b) {
    // Your code goes here.
	while((SPI2->SR & SPI_SR_TXE) == 0);
	SPI2->DR = 0x200 + b;
}

void spi_init_lcd(void) {
    // Your code goes here.
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	//GPIOB->BSRR = 1<<12; // set NSS high
	//GPIOB->BRR = (1<<13) + (1<<15); // set SCK and MOSI low
	// Now, configure pins for output.
	GPIOB->MODER &= ~(3<<(2*12));
	GPIOB->MODER |= (2<<(2*12));
	GPIOB->MODER &= ~( (3<<(2*13)) | (3<<(2*15)) );
	GPIOB->MODER |= (2<<(2*13)) | (2<<(2*15));

	// SPI Channel 2
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
	SPI2->CR1 |= SPI_CR1_MSTR | SPI_CR1_BR;
	SPI2->CR1 |= SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE;
	//SPI2->CR2 &= ~(SPI_CR2_DS);
	SPI2->CR2 = SPI_CR2_SSOE | SPI_CR2_NSSP | SPI_CR2_DS_3 | SPI_CR2_DS_0;
	SPI2->CR1 |= SPI_CR1_SPE;

	generic_lcd_startup();
}

void nondma_display1(const char *s) {
    // put the cursor on the beginning of the first line (offset 0).
    cmd(0x80 + 0);
    int x;
    for(x=0; x<16; x+=1)
        if (s[x])
            data(s[x]);
        else
            break;
    for(   ; x<16; x+=1)
        data(' ');
}

void nondma_display2(const char *s) {
    // put the cursor on the beginning of the second line (offset 64).
    cmd(0x80 + 64);
    int x;
    for(x=0; x<16; x+=1)
        if (s[x] != '\0')
            data(s[x]);
        else
            break;
    for(   ; x<16; x+=1)
        data(' ');
}

void init_lcd_all(void) {
	// Configure the function pointers.
	cmd = spi_cmd;
	data = spi_data;
	display1 = nondma_display1;
	display2 = nondma_display2;
	// Initialize the display.
	spi_init_lcd();
}

void lcd_display_score(short score) {
    // Display some interesting things.
    char msg[15] = "Score: ";
    char charscore[8];
    // covert score from int to char
    itoa(score, charscore, 10);
    // concatenate msg and charscore
    strcat(msg, charscore);

	display1(msg);
    nano_wait(40000000);
}

void lcd_display_main() {
    // Display some interesting things.
    char msg[15] = "Press to Start";
	display1(msg);
    nano_wait(40000000);
}
