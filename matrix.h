#ifndef MATRIX_H_
#define MATRIX_H_

#include "init.h"
#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

void generate_image(void);
void generate_row(int);
void mask_canvas(int, int, int, int, uint8_t(*)[]);
void clear_display();
void gameover();
void draw_title();
void draw_background();
void draw_bird(int, short);
void draw_pipe(int, int);
void bird_fly();
//void clear_pipe(double, double, double);

#endif /* MATRIX_H_ */
