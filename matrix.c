#include "matrix.h"
#include "init.h"
#include "lcd.h"


uint8_t  canvas[ROW][COL] =
{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

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

uint8_t char_f[9][5] =
        {
				{5, 5, 5, 5, 5},
				{5, 5, 5, 5, 5},
				{5, 7, 7, 7, 7},
				{5, 7, 0, 0, 0},
				{5, 5, 5, 5, 0},
				{5, 7, 7, 7, 0},
				{5, 7, 0, 0, 0},
				{5, 7, 0, 0, 0},
				{5, 7, 0, 0, 0}
        };

uint8_t char_l[9][5] =
        {
				{5, 5, 0, 0, 0},
				{5, 5, 0, 0, 0},
				{5, 5, 0, 0, 0},
				{5, 5, 0, 0, 0},
				{5, 5, 0, 0, 0},
				{5, 5, 0, 0, 0},
				{5, 5, 7, 7, 7},
				{5, 5, 5, 5, 7},
				{5, 5, 5, 5, 7}
        };

uint8_t char_a[9][5] =
        {
				{0, 0, 5, 0, 0},
				{0, 5, 5, 5, 0},
				{5, 5, 0, 5, 7},
				{5, 5, 0, 5, 7},
				{5, 5, 5, 5, 7},
				{5, 5, 5, 5, 7},
				{5, 5, 0, 5, 7},
				{5, 5, 0, 5, 7},
				{5, 5, 0, 5, 7}
        };

uint8_t char_p[9][6] =
        {
				{5, 5, 5, 5, 5, 0},
				{5, 5, 0, 0, 5, 5},
				{5, 5, 0, 0, 5, 5},
				{5, 5, 5, 5, 5, 5},
				{5, 5, 7, 7, 7, 0},
				{5, 5, 7, 0, 0, 0},
				{5, 5, 7, 0, 0, 0},
				{5, 5, 7, 0, 0, 0},
				{5, 5, 7, 0, 0, 0}
        };

uint8_t char_y[9][5] =
        {
				{5, 5, 0, 5, 5},
				{5, 5, 0, 5, 5},
				{5, 5, 0, 5, 5},
				{5, 5, 0, 5, 5},
				{5, 5, 5, 5, 5},
				{0, 5, 5, 5, 5},
				{0, 0, 0, 7, 5},
				{7, 7, 7, 7, 5},
				{5, 5, 5, 5, 5}
        };

uint8_t char_b[9][6] =
        {
				{5, 5, 5, 5, 5, 0},
				{5, 5, 0, 0, 5, 5},
				{5, 5, 0, 0, 5, 5},
				{5, 5, 5, 5, 5, 0},
				{5, 5, 5, 5, 5, 0},
				{5, 5, 0, 0, 5, 7},
				{5, 5, 0, 0, 5, 7},
				{5, 5, 5, 5, 5, 7},
				{7, 7, 7, 7, 7, 0}
        };

uint8_t char_i[9][4] =
        {
				{5, 5, 5, 5},
				{0, 5, 5, 0},
				{0, 5, 5, 0},
				{0, 5, 5, 0},
				{0, 5, 5, 0},
				{0, 5, 5, 0},
				{0, 5, 5, 0},
				{0, 5, 5, 0},
				{Y, Y, Y, Y}
        };

uint8_t char_r[9][6] =
        {
				{5, 5, 5, 5, 5, 0},
				{5, 5, 0, 0, 5, 7},
				{5, 5, 0, 0, 5, 7},
				{5, 5, 5, 5, 5, 0},
				{5, 5, 5, 5, 5, 0},
				{5, 7, 0, 0, 5, 7},
				{5, 7, 0, 0, 5, 7},
				{5, 7, 0, 0, 5, 7},
				{5, 7, 0, 0, 5, 7}
        };

uint8_t char_d[9][6] =
        {
				{5, 5, 5, 5, 0, 0},
				{5, 5, 5, 5, 5, 0},
				{5, 5, 0, 0, 5, 5},
				{5, 5, 0, 0, 5, 5},
				{5, 5, 0, 0, 5, 5},
				{5, 5, 0, 0, 5, 5},
				{5, 5, 0, 0, 5, 7},
				{5, 5, 5, 5, 7, 0},
				{7, 7, 7, 7, 0, 0}
        };

uint8_t char_g[10][7] =
        {
				{0, 0, Y, Y, Y, 0, 0},
				{0, Y, Y, Y, Y, Y, 0},
				{Y, Y, 0, 0, 0, Y, 0},
				{Y, Y, 0, 0, 0, 0, 0},
				{Y, Y, 0, 0, 0, 0, 0},
				{Y, Y, 0, Y, Y, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{W, Y, 0, 0, 0, Y, W},
				{0, W, Y, Y, Y, W, 0},
				{0, 0, W, W, W, 0, 0}
        };

uint8_t char_m[9][7] =
        {
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, Y, 0, Y, Y, Y},
				{Y, Y, Y, 0, Y, Y, Y},
				{Y, Y, Y, Y, Y, Y, Y},
				{Y, Y, 0, Y, 0, Y, Y},
				{Y, Y, 0, Y, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y}
        };

uint8_t char_e[10][5] =
        {
        		{Y, Y, Y, Y, Y},
				{Y, Y, W, W, W},
				{Y, Y, 0, 0, 0},
				{Y, Y, 0, 0, 0},
				{Y, Y, Y, Y, Y},
				{Y, Y, W, W, W},
				{Y, Y, 0, 0, 0},
				{Y, Y, 0, 0, 0},
				{Y, Y, Y, Y, Y},
				{W, W, W, W, W}
        };

uint8_t char_o[9][7] =
        {
				{0, 0, Y, Y, Y, 0, 0},
				{0, Y, Y, Y, Y, Y, 0},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{W, Y, 0, 0, 0, Y, W},
				{0, W, Y, Y, Y, W, 0},
				{0, 0, W, W, W, 0, 0}
        };

uint8_t char_v[10][7] =
        {
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{Y, Y, 0, 0, 0, Y, Y},
				{W, Y, 0, 0, 0, Y, W},
				{0, W, Y, 0, Y, W, 0},
				{0, 0, W, Y, W, 0, 0},
				{0, 0, 0, W, 0, 0, 0}
        };


uint8_t background[7][COL] =
{
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
};

uint8_t bird[3][8][8] =
{
        {
        		{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
        },

		{
				{0, 0, 0, Y, Y, W, W, 0},
				{0, 0, Y, Y, W, 0, 0, W},
				{0, Y, Y, Y, W, 0, 0, W},
				{0, Y, Y, Y, Y, W, W, W},
				{W, W, W, W, Y, R, R, R},
				{W, W, W, W, Y, R, 0, 0},
				{0, 0, Y, Y, Y, R, R, R},
				{0, 0, 0, 0, 0, 0, 0, 0}
		},

		{
				{0, 0, 0, Y, Y, W, W, 0},
				{0, 0, Y, Y, W, 0, 0, W},
				{0, Y, Y, Y, W, 0, 0, W},
				{0, Y, Y, Y, Y, W, W, W},
				{0, Y, W, W, Y, R, R, R},
				{0, W, W, W, Y, R, 0, 0},
				{W, W, W, Y, Y, R, R, R},
				{W, W, 0, 0, 0, 0, 0, 0}
		}
};

uint8_t pipes_top[2][ROW][12] =
{
		 {
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, G, G, G, G, G, G, G, G, G, G, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		 },

		 {
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, G, G, G, G, G, G, G, G, G, G, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

		 }
};

uint8_t pipes_bot[2][25][12] =
{
		{
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, G, G, G, G, G, G, G, G, G, G, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0}
		},

		{
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, G, G, G, G, G, G, G, G, G, G, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0}
		}
};

// Global Variable
short curheight = 32;
short isgameover = 0;
short i = 63;
short j = 89;
short k = 115;
uint8_t a = 1;
uint8_t b = 0;
uint8_t c = 1;
short score = 0;

void generate_row(short curRow) {
    for (short j = 0; j < COL; j++) {
        // clear all color data before setting new color values
        GPIOC->BRR = 0b111111;

        // set color
        GPIOC->BSRR = canvas[curRow][j];// * (WHITE | (WHITE<<3));

        // Clock toggle
        GPIOC->BSRR = 1<<CLK; 	// set
        GPIOC->BRR = 1<<CLK;	// clear
    }

    // turn on OE then LAT
    GPIOC->BSRR = 1<<OE;		//OE;
    GPIOC->BSRR = 1<<LAT;		//LAT;

    // clear the target row value and set it to current row value
    if(curRow != ROW){
    	GPIOC->BRR = 0b111111<<PINA;	//SE0;
    	GPIOC->BSRR = curRow<<PINA;	//SE0;
    }


    // turn off LAT then OE
    GPIOC->BRR = 1<<LAT;		//LAT;
    GPIOC->BRR = 1<<OE;		//OE;
}

void generate_image() {
    // clear output values for pins
    //GPIOC->BRR = 0b11111111111111;
    // print the image row by row
    for (short i = 0; i <= ROW; i++) {
        generate_row(i);
    }
}

void mask_canvas(short selRow, short selCol, short imageHeight, short imageWidth, uint8_t (*imgptr)[imageWidth]) {
    for (short i = 0; i < imageHeight; i++) {
        // targeted values
        short tarRow = selRow + i;
        uint8_t colorShift = 0;

        // mask to clear the colors
        uint8_t clearMask = 0b111;

        // check if vertically out of dimension
        if (((tarRow) < (ROW*2)) && ((tarRow) >= 0)) {
            if ((tarRow) >= ROW) {
                tarRow -= ROW;
                colorShift = 3;
                clearMask <<= 3;
            }

            for (short j = 0; j < imageWidth; j++) {
                short tarCol = selCol + j;

                // check if horizontally out of dimension
                if (((tarCol) < COL) && ((tarCol) >= 0)) {

                    // clear the current canvas
                    canvas[tarRow][tarCol] &= ~clearMask;

                    // draw the image
                    canvas[tarRow][tarCol] |= imgptr[i][j] << colorShift;
                }
            }
        }
    }
}

void clear_display() {
	for (short i = 0; i < ROW; i++) {
	        // mask to clear the colors
	        uint8_t clearMask = 0b111111;

		for (short j = 0; j < COL; j++) {
			// clear the current canvas
			canvas[i][j] &= ~clearMask;;
		}
	}
}

void draw_title() {
	mask_canvas(3, 5, 9, 5, char_f); //F
	mask_canvas(5, 10, 9, 5, char_l); //L
	mask_canvas(3, 15, 9, 5, char_a); //A
	mask_canvas(9, 20, 9, 6, char_p); //P
	mask_canvas(9, 26, 9, 6, char_p); //P
	mask_canvas(7, 32, 9, 5, char_y); //Y
	mask_canvas(4, 37, 9, 6, char_b); //B
	mask_canvas(5, 43, 9, 4, char_i); //I
	mask_canvas(5, 47, 9, 6, char_r); //R
	mask_canvas(4, 53, 9, 6, char_d); //D
}

void draw_gameover() {
	mask_canvas(3, 7, 10, 7, char_g); //G
	mask_canvas(5, 14, 9, 5, char_a); //A
	mask_canvas(3, 19, 9, 7, char_m); //M
	mask_canvas(5, 26, 10, 5, char_e); //E
	//mask_canvas(9, 24, 11, 7, char_blank); //space
	mask_canvas(7, 33, 9, 7, char_o); //O
	mask_canvas(4, 40, 10, 7, char_v); //V
	mask_canvas(5, 47, 10, 5, char_e); //E
	mask_canvas(5, 52, 9, 6, char_r); //R
}

void draw_background() {
	short height = (short)sizeof(background) / sizeof(background[0]);
	short width = (short)sizeof(background[0]) / sizeof(background[0][0]);
	mask_canvas(56, 0, height, width, background);
}

void draw_bird(short index) {
	if((GPIOA->IDR & GPIO_IDR_8) == GPIO_IDR_8){
		short height = (short)sizeof(bird[2]) / sizeof(bird[2][0]);
		short width = (short)sizeof(bird[2][0]) / sizeof(bird[2][0][0]);
		curheight -= 6;
		mask_canvas(curheight + 6, 20, height, width, bird[0]);
		mask_canvas(curheight, 20, height, width, bird[2]);
	}

	else{
		short height = (short)sizeof(bird[index]) / sizeof(bird[index][0]);
		short width = (short)sizeof(bird[index][0]) / sizeof(bird[index][0][0]);
		curheight += 2;
		mask_canvas(curheight - 2, 20, height, width, bird[0]);
		mask_canvas(curheight, 20, height, width, bird[index]);
	}

	if(curheight >= ROW){
		if(canvas[curheight - 32][19] != 0 || canvas[curheight - 32][26] != 0 || canvas[curheight - 25][19] != 0 || canvas[curheight - 25][26] != 0){
			isgameover = 1;
		}
	}

	else if(curheight < ROW && curheight + 7 >= ROW){
		if(canvas[curheight][19] != 0 || canvas[curheight][26] != 0 || canvas[curheight - 25][19] != 0 || canvas[curheight - 25][26] != 0){
			isgameover = 1;
		}
	}

	else if(curheight + 7 < ROW){
		if((canvas[curheight][19] != 0) || (canvas[curheight][26] != 0) || canvas[curheight + 7][19] != 0 || canvas[curheight + 7][26] != 0){
			isgameover = 1;
		}
	}

	if(curheight >= 49){
		isgameover = 1;
	}
}

/*void bird_fly(){
	if((GPIOA->IDR & GPIO_IDR_8) == GPIO_IDR_8){
		short height = (short)sizeof(bird[2]) / sizeof(bird[2][0]);
		short width = (short)sizeof(bird[2][0]) / sizeof(bird[2][0][0]);
		curheight -= 6;
		mask_canvas(curheight + 6, 20, height, width, bird[0]);

			if(curheight >= ROW){
				if((canvas[curheight - 32][19] == (G << 3)) || (canvas[curheight - 32][26] == (G << 3)) || canvas[curheight - 25][19] == (G << 3) || canvas[curheight - 25][26] == (G << 3)){
					isgameover = 1;
				}
			}

			else if(curheight < ROW && curheight + 7 >= ROW){
				if((canvas[curheight][19] == G) || (canvas[curheight][26] == G) || canvas[curheight - 25][19] == (G << 3) || canvas[curheight - 25][26] == (G << 3)){
					isgameover = 1;
				}
			}

			else if(curheight < ROW && curheight + 7 < ROW){
				if((canvas[curheight][19] == G) || (canvas[curheight][26] == G) || canvas[curheight + 7][19] == G || canvas[curheight + 7][26] == G){
					isgameover = 1;
				}
			}

		mask_canvas(curheight, 20, height, width, bird[2]);
	}
}*/

void draw_pipe(short index, short col) {
	short height = (short)sizeof(pipes_top[index]) / sizeof(pipes_top[index][0]);
	short width = (short)sizeof(pipes_top[index][0]) / sizeof(pipes_top[index][0][0]);
	mask_canvas(0, col, height, width, pipes_top[index]);

	height = (short)sizeof(pipes_bot[index]) / sizeof(pipes_bot[index][0]);
	width = (short)sizeof(pipes_bot[index][0]) / sizeof(pipes_bot[index][0][0]);
	mask_canvas(32, col, height, width, pipes_bot[index]);
}

void init_timer6(){
	// clock to timer 6
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6->CR1 &= ~TIM_CR1_CEN;
	// count up
	TIM6->CR1 &= ~TIM_CR1_DIR;
	TIM6->PSC = 480 - 1;
	TIM6->ARR = 100 - 1;
	TIM6->DIER |= TIM_DIER_UIE;
	TIM6->CR1 |= TIM_CR1_CEN;
	NVIC->ISER[0] = 1 << TIM6_DAC_IRQn;
}

void TIM6_DAC_IRQHandler(){
	TIM6->CR1 &= ~TIM_CR1_CEN;
	generate_image();

	if ((TIM6->SR & TIM_SR_UIF) != 0) {
		TIM6->SR &= ~TIM_SR_UIF;
	}

	TIM6->CR1 |= TIM_CR1_CEN;
}

void init_timer3(){
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->CR1 &= ~TIM_CR1_CEN;
	TIM3->PSC = 12000 - 1;
	TIM3->ARR = 1000 - 1;
	TIM3->DIER |= TIM_DIER_UIE;
	TIM3->CR1 |= 2 << 8;
	TIM3->CR1 |= TIM_CR1_CEN;
	NVIC->ISER[0] = (1 << TIM3_IRQn) | (1 << EXTI4_15_IRQn);
}

void EXTI4_15_IRQHandler() {
	short height = (short)sizeof(bird[2]) / sizeof(bird[2][0]);
	short width = (short)sizeof(bird[2][0]) / sizeof(bird[2][0][0]);
	//curheight -= 6;

	if(curheight >= ROW){
		if((canvas[curheight - 32][22] == (G << 3)) || (canvas[curheight - 32][28] == (G << 3)) || canvas[curheight - 25][22] == (G << 3) || canvas[curheight - 25][28] == (G << 3)){
			isgameover = 1;
		}
	}

	else if((curheight < ROW) && (curheight + 7 >= ROW)){
		if((canvas[curheight][22] == G) || (canvas[curheight][28] == G) || canvas[curheight - 25][22] == (G << 3) || canvas[curheight - 25][28] == (G << 3)){
			isgameover = 1;
		}
	}

	else if(curheight + 7 < ROW){
		if((canvas[curheight][22] == G) || (canvas[curheight][28] == G) || canvas[curheight + 7][22] == G || canvas[curheight + 7][28] == G){
			isgameover = 1;
		}
	}

	curheight -= 6;
	mask_canvas(curheight + 6, 20, height, width, bird[0]);
	mask_canvas(curheight, 20, height, width, bird[2]);

	if(isgameover == 1){
		gameover();
	}

	EXTI->PR |= EXTI_PR_PR8;
}

void TIM3_IRQHandler(){
	TIM3->CR1 &= ~TIM_CR1_CEN;
	if(i == 63 && j == 89 && k == 115){
		a = rand() % 2;
		b = rand() % 2;
		c = rand() % 2;
	}

	draw_pipe(a, i--);
	if (i <= -14) {
		i = 63;
		a = rand() % 2;
	}

	draw_pipe(b, j--);
	if (j <= -14) {
		j = 63;
		b = rand() % 2;
	}

	draw_pipe(c, k--);
	if (k <= -14) {
		k = 63;
		c = rand() % 2;
	}

	draw_background();

	short height = (short)sizeof(bird[1]) / sizeof(bird[1][0]);
	short width = (short)sizeof(bird[1][0]) / sizeof(bird[1][0][0]);
	curheight += 1;

	if(curheight >= ROW){
		if((canvas[curheight - 32][20] == (G << 3)) || (canvas[curheight - 32][27] == (G << 3)) || canvas[curheight - 25][20] == (G << 3) || canvas[curheight - 25][27] == (G << 3)){
			isgameover = 1;
		}
	}

	else if(curheight < ROW && curheight + 7 >= ROW){
		if((canvas[curheight][20] == G) || (canvas[curheight][27] == G) || canvas[curheight - 25][20] == (G << 3) || canvas[curheight - 25][27] == (G << 3)){
			isgameover = 1;
		}
	}

	else if(curheight < ROW && curheight + 7 < ROW){
		if((canvas[curheight][20] == G) || (canvas[curheight][27] == G) || canvas[curheight + 7][20] == G || canvas[curheight + 7][27] == G){
			isgameover = 1;
		}
	}

	//curheight += 1;
	mask_canvas(curheight - 1, 20, height, width, bird[0]);
	mask_canvas(curheight, 20, height, width, bird[1]);

	if(isgameover == 1){
		gameover();
	}

	if(curheight >= 49){
		isgameover = 1;
		gameover();
	}

	if(i == 16 || j == 16 || k == 16){
		score++;
	}

	if ((TIM3->SR & TIM_SR_UIF) != 0) {
		TIM3->SR &= ~TIM_SR_UIF;
	}
	TIM3->CR1 |= TIM_CR1_CEN;
}

void gameover(){
	TIM3->CR1 &= ~TIM_CR1_CEN;

	while(1){
		draw_gameover();
		generate_image();
	}
}

void start_game() {
	clear_display();

	init_timer6();
	init_timer3();
	while (!isgameover) {
		lcd_display_score(score);
	}

	gameover();
}
