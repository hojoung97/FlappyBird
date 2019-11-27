
#ifndef MATRIX_H_
#define MATRIX_H_

#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

void generate_image(void);
void generate_row(int);
void mask_canvas(uint8_t, int, int, int, int, uint8_t(*)[]);
void clear_display();

void draw_arrow(int SelRow);

#endif /* MATRIX_H_ */
