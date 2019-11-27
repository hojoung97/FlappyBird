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


int main(void)
{
    // initialize the matrix pins with port C
    init_gpio();

    while (1){
    	//draw_title();
    	draw_background();
    	//draw_bird();
    	draw_pipe(0);

    }
}
