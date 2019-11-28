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
uint8_t char_blank[11][7] =
{
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
};


int main(void)
{
	//short
    // initialize the matrix pins with port C
    init_gpio();

    while (((GPIOA->IDR) & GPIO_IDR_8) != GPIO_IDR_8) {
    	draw_title();
    	draw_bird(rand() % 2 + 1, 32);
    	draw_background();
    	generate_image();
    }
    mask_canvas(3, 3, 20, 58, char_blank);
    mask_canvas(31, 0, 25, 64, char_blank);
    init_timer6();
	init_timer3();
    while(1){
    	bird_fly();
    	gameover();
    	//nano_wait(100000000);
    }
}
