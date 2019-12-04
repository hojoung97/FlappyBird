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
#include "init.h"
#include "matrix.h"
#include "lcd.h"

#include <stdio.h>
#include <stdlib.h>


// global score variable


int main(void)
{
    // initialize the matrix pins with port C
    init_gpio();
    // initialize LCD display
    init_lcd_all();
    lcd_display_main();

    // wait for user input and display the title screen
    while (((GPIOA->IDR) & GPIO_IDR_8) != GPIO_IDR_8) {
    	draw_title();
    	//draw_bird(rand() % 2 + 1);
    	draw_background();
    	generate_image();
    }

    init_dac();
    init_syscfg();
	start_game();
}
