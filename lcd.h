/*
 * lcd.h
 *
 *  Created on: Nov 28, 2019
 *      Author: jang88
 */

#ifndef LCD_H_
#define LCD_H_

void generic_lcd_startup(void);
void spi_cmd(char b);
void spi_data(char b);
void spi_init_lcd(void);
void lcd_display_score(short);
void nondma_display1(const char *s);
void nondma_display2(const char *s);
void init_lcd_all(void);
void lcd_display_main();

#endif /* LCD_H_ */
