/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

#define R1 0
#define B1 1
#define G1 2
#define R2 3
#define B2 4
#define G2 5
#define A 6
#define B 7
#define C 8
#define D 9
#define E 10
#define CLK 11
#define LAT 12
#define OE 13

uint8_t square[16][64] =
    {
    		{0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    		{0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0b100, 0b100, 0b100, 0b100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

int main(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	// use from PC0 ~ PC13
	GPIOC->MODER &= ~0b1111111111111111111111111111;
	GPIOC->MODER |= 0b0101010101010101010101010101;

	GPIOC->BRR |= 0b11111111111111;
	while (1){

		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 64; j++) {
				GPIOC->BRR = 0b111111;      // clear all color data before setting new color values
				GPIOC->BSRR = square[i][j] & (0b111 | (0b000<<3));

				//color
				//GPIOC->BSRR = 0b000000;

				// Clock toggle
				GPIOC->BSRR = 1<<CLK; //CLK
				// nanosleep(5000);
				// for(int x = 0; x<200; x+=83);
				GPIOC->BRR = 1<<CLK;	//CLK;
				// for(int x = 0; x<200; x+=83);
				// nanosleep(5000);
			 }

			 GPIOC->BSRR = 1<<OE;		//OE;
			 GPIOC->BSRR = 1<<LAT;		//LAT;
			 GPIOC->BRR = 0b11111<<A;	//SE0;
			 GPIOC->BSRR = i<<A;	//SE0);
			 GPIOC->BRR = 1<<LAT;		//LAT;
			 GPIOC->BRR = 1<<OE;		//OE;
		}

		/*
		GPIOC->BRR = 0b111111;
		GPIOC->BSRR = 0b001001;

		GPIOC->BSRR = 1<<CLK;
		GPIOC->BRR = 1<<CLK;

		GPIOC->BSRR = 1<<OE;		//OE;
		GPIOC->BSRR = 1<<LAT;		//LAT;
		GPIOC->BRR = 0b11111<<A;	//SE0;
		GPIOC->BSRR = 3<<A;	//SE0;
		GPIOC->BRR = 1<<LAT;		//LAT;
		GPIOC->BRR = 1<<OE;		//OE;

		GPIOC->BRR = 0b111111;
		GPIOC->BSRR = 0b001001;

		GPIOC->BSRR = 1<<CLK;
		GPIOC->BRR = 1<<CLK;

		GPIOC->BSRR = 1<<OE;		//OE;
		GPIOC->BSRR = 1<<LAT;		//LAT;
		GPIOC->BRR = 0b11111<<A;	//SE0;
		GPIOC->BSRR = 5<<A;	//SE0;
		GPIOC->BRR = 1<<LAT;		//LAT;
		GPIOC->BRR = 1<<OE;		//OE;
		*/
	}

	//for(;;);
}
