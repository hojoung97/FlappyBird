/*
 * init.h
 *
 *  Created on: 2019. 11. 26.
 *      Author: ¿Â»£¡ﬂ
 */

#ifndef INIT_H_
#define INIT_H_

#define R1 0
#define B1 1
#define G1 2
#define R2 3
#define B2 4
#define G2 5
#define PINA 6
#define PINB 7
#define PINC 8
#define PIND 9
#define PINE 10
#define CLK 11
#define LAT 12
#define OE 13

#define ROW 32
#define COL 64

#define RED 1
#define BLUE 2
#define GREEN 4
#define WHITE 7

void init_gpio(void);
void nano_wait(unsigned int);

#endif /* INIT_H_ */
