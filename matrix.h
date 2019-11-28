#ifndef MATRIX_H_
#define MATRIX_H_

#include "init.h"
#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

void generate_image(void);
void generate_row(short);
void mask_canvas(short, short, short, short, uint8_t(*)[]);
void clear_display();
void gameover();
void draw_title();
void draw_background();
void draw_bird(short, short);
void draw_pipe(short, short);
void bird_fly();
short collision();
void start_game();

#endif /* MATRIX_H_ */
