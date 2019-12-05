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

#define R 1
#define B 2
#define G 4
#define W 7
#define BK 0
#define PU 3
#define SKY 6
#define Y 5

void init_gpio(void);
void nano_wait(unsigned int);
void init_timer6(void);
void init_timer2(void);
void init_timer3(void);
void init_timer15(void);
void init_dac();

#endif /* INIT_H_ */
