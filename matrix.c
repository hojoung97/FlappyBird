#include "matrix.h"
#include "init.h"
#include "lcd.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
		{5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G},
		{G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5},
		{5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G},
		{G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5},
		{5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G, 5, G}
};

uint8_t bird[3][7][8] =
{
        {
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
				{0, 0, Y, Y, Y, R, R, R}
		},

		{
				{0, 0, 0, Y, Y, W, W, 0},
				{0, 0, Y, Y, W, 0, 0, W},
				{0, Y, Y, Y, W, 0, 0, W},
				{0, Y, Y, Y, Y, W, W, W},
				{0, Y, W, W, Y, R, R, R},
				{0, W, W, W, Y, R, 0, 0},
				{W, W, W, Y, Y, R, R, R}
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
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		 },
/*
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
		 },*/

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
					{0, G, G, G, G, G, G, G, G, G, G, 0},
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
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0}
		},
		/*
		{
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
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0},
					{0, 0, G, G, G, G, G, G, G, G, 0, 0}
		},*/
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
					{0, 0, G, G, G, G, G, G, G, G, 0, 0}
		}
};

// Global Variable
short curheight = 26;
short isgameover = 0;
short makegameover = 0;
short i = 63;
short j = 89;
short k = 115;
uint8_t a = 1;
uint8_t b = 0;
uint8_t c = 1;
short score = 0;
int offset = 0;
#define RATE 100000
#define N 750
short int wavetable[N];

float notes[] =
{      //  C5    C#      D       D#      E       F       F#      G       G#     A      A#      B
		//523, 554.37, 587.33, 622.25, 659.26, 698.46, 739.99, 783.99, 830.61, 880, 932.33, 987.77
		/*2093, //C6 with upper octave
		0,		 //Blank
		1568,	 //G5
		0,		 //Blank
		1318.52,  //E5
		0,		 //Blank
		1760, 	 //A5
		1975.54,  //B5
		1864.66,  //A#5
		1760,     //A5
		1568,  //G5
		2093, //C6
		3135.96, //G6
		3520, //A6
		0,		 //Blank
		2793.82, //F6
		3135.96, //G6
		0,		 //Blank
		2637.02, //E6
		2093, //C6
		2349.32, //D6
		1975.54,	 //B5*/
		5274,
		5274,
		0,
		5274,
		0,
		4186,
		5274,
		0,
		6272,
		0,
		0,
		0,
		3136,
		0,
		0,
		0,
		4186,
		0,
		0,
		3136,
		0,
		0,
		2638,
		0,
		0,
		3520,
		3952,
		0,
		3730,
		3520,
		0,
		3136,
		5274,
		6272,
		7040,
		0,
		5588,
		6272,
		0,
		5274,
		0,
		4186, //C7
		4698, //D7
		3952, //B6
		0,
		0
		/*
		510,
		0,
		0,
		380,
		0,
		0,
		320,
		0,
		0,
		440,
		480,
		0,
		450,
		430,
		0,
		380,
		660,
		760,
		860,
		0,
		700,
		760,
		0,
		660,
		0,
		520,
		580,
		480,
		0,
		0*/

};

short noteind = 0;
int step;
void init_wavetable(void)
{
	int x;
	for(x=0; x<N; x++) {
		wavetable[x] = 32767 * sin(2 * M_PI * x / N);
	}
}

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
	mask_canvas(7, 33, 9, 7, char_o); //O
	mask_canvas(4, 40, 10, 7, char_v); //V
	mask_canvas(5, 47, 10, 5, char_e); //E
	mask_canvas(5, 52, 9, 6, char_r); //R
}

void draw_background() {
	short height = (short)sizeof(background) / sizeof(background[0]);
	short width = (short)sizeof(background[0]) / sizeof(background[0][0]);
	mask_canvas(57, 0, height, width, background);
}

void draw_bird(short index) {
	short height = (short)sizeof(bird[2]) / sizeof(bird[2][0]);
	short width = (short)sizeof(bird[2][0]) / sizeof(bird[2][0][0]);
	mask_canvas(curheight, 20, height, width, bird[index]);
}

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
	//TIM6->CR1 &= ~TIM_CR1_CEN;
	TIM6->PSC = 50 - 1;
	TIM6->ARR = 75 - 1;
	TIM6->DIER |= TIM_DIER_UIE;
	TIM6->CR1 |= TIM_CR1_CEN;
	NVIC_SetPriority(TIM6_DAC_IRQn, 0);
	NVIC->ISER[0] = 1 << TIM6_DAC_IRQn;
}

void TIM6_DAC_IRQHandler(){
	DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
	TIM6->SR &= ~TIM_SR_UIF;

	offset += step;

	if((offset >> 16) >= N){
		offset -= N << 16;
	}

	int sample = wavetable[offset >> 16];
	sample = sample / 16 + 2048;

	if(sample > 4095){
		sample = 4095;
	}
	else if(sample < 0){
		sample = 0;
	}

	DAC->DHR12R1 = sample;
}

void init_timer15(){
	RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;
	//TIM15->CR1 &= ~TIM_CR1_CEN;
	TIM15->PSC = 4800 - 1;
	TIM15->ARR = 1500 - 1;
	TIM15->DIER |= TIM_DIER_UIE;
	TIM15->CR1 |= TIM_CR1_CEN;
	NVIC->ISER[0] = 1 << TIM15_IRQn;
	NVIC_SetPriority(TIM15_IRQn, 1);
}

void TIM15_IRQHandler(){
	TIM15->SR &= ~TIM_SR_UIF;

	if(noteind >= sizeof(notes) / sizeof(notes[0])){
		noteind = 16;
	}

	step = notes[noteind++] * N / 100000.0 * (1 << 16);
}

void init_timer2(){
	// clock to timer 2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 &= ~TIM_CR1_CEN;
	// count up
	TIM2->CR1 &= ~TIM_CR1_DIR;
	TIM2->PSC = 480 - 1;
	TIM2->ARR = 100 - 1;
	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->CR1 |= TIM_CR1_CEN;
	NVIC->ISER[0] = 1 << TIM2_IRQn;
	NVIC_SetPriority(TIM2_IRQn, 3);
}

void TIM2_IRQHandler(){
	TIM2->CR1 &= ~TIM_CR1_CEN;

	generate_image();
	if (makegameover == 1) {
		isgameover = 1;
	}

	if ((TIM2->SR & TIM_SR_UIF) != 0) {
		TIM2->SR &= ~TIM_SR_UIF;
	}

	TIM2->CR1 |= TIM_CR1_CEN;
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
	NVIC_SetPriority(TIM3_IRQn, 3);
}

void EXTI4_15_IRQHandler() {
	short height = (short)sizeof(bird[2]) / sizeof(bird[2][0]);
	short width = (short)sizeof(bird[2][0]) / sizeof(bird[2][0][0]);

	curheight -= 5;

	/*
	if(curheight >= ROW){
		if(canvas[curheight - 32][20] == (G << 3) ||
		canvas[curheight - 31][20] == (G << 3) ||
		canvas[curheight - 30][20] == (G << 3) ||
		canvas[curheight - 29][20] == (G << 3) ||
		canvas[curheight - 28][20] == (G << 3) ||
		canvas[curheight - 27][20] == (G << 3) ||
		canvas[curheight - 26][20] == (G << 3) ||
		canvas[curheight - 25][20] == (G << 3) ||
		canvas[curheight - 32][27] == (G << 3) ||
		canvas[curheight - 31][27] == (G << 3) ||
		canvas[curheight - 30][27] == (G << 3) ||
		canvas[curheight - 29][27] == (G << 3) ||
		canvas[curheight - 28][27] == (G << 3) ||
		canvas[curheight - 27][27] == (G << 3) ||
		canvas[curheight - 26][27] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)){
			makegameover = 1;
		}
	}


	if(curheight < ROW && curheight + 7 >= ROW){
		if(canvas[curheight - 32][20] == G ||
		canvas[curheight - 31][20] == G ||
		canvas[curheight - 30][20] == G ||
		canvas[curheight - 29][20] == G ||
		canvas[curheight - 28][20] == G ||
		canvas[curheight - 27][20] == G ||
		canvas[curheight - 26][20] == G ||
		canvas[curheight - 25][20] == G ||
		canvas[curheight - 32][27] == (G << 3) ||
		canvas[curheight - 31][27] == (G << 3) ||
		canvas[curheight - 30][27] == (G << 3) ||
		canvas[curheight - 29][27] == (G << 3) ||
		canvas[curheight - 28][27] == (G << 3) ||
		canvas[curheight - 27][27] == (G << 3) ||
		canvas[curheight - 26][27] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)){
			makegameover = 1;
		}
	}*/

	if(curheight + 7 >= ROW){
		if(canvas[curheight - 32][20] == (G << 3)||
		canvas[curheight - 31][20] == (G << 3) ||
		canvas[curheight - 30][20] == (G << 3) ||
		canvas[curheight - 29][20] == (G << 3) ||
		canvas[curheight - 28][20] == (G << 3) ||
		canvas[curheight - 27][20] == (G << 3) ||
		canvas[curheight - 26][20] == (G << 3) ||
		canvas[curheight - 25][20] == (G << 3) ||
		canvas[curheight - 32][21] == (G << 3) ||
		canvas[curheight - 31][21] == (G << 3) ||
		canvas[curheight - 30][21] == (G << 3) ||
		canvas[curheight - 29][21] == (G << 3) ||
		canvas[curheight - 28][21] == (G << 3) ||
		canvas[curheight - 27][21] == (G << 3) ||
		canvas[curheight - 26][21] == (G << 3) ||
		canvas[curheight - 25][21] == (G << 3) ||
		canvas[curheight - 32][22] == (G << 3) ||
		canvas[curheight - 31][22] == (G << 3) ||
		canvas[curheight - 30][22] == (G << 3) ||
		canvas[curheight - 29][22] == (G << 3) ||
		canvas[curheight - 28][22] == (G << 3) ||
		canvas[curheight - 27][22] == (G << 3) ||
		canvas[curheight - 26][22] == (G << 3) ||
		canvas[curheight - 25][22] == (G << 3) ||
		canvas[curheight - 32][23] == (G << 3) ||
		canvas[curheight - 31][23] == (G << 3) ||
		canvas[curheight - 30][23] == (G << 3) ||
		canvas[curheight - 29][23] == (G << 3) ||
		canvas[curheight - 28][23] == (G << 3) ||
		canvas[curheight - 27][23] == (G << 3) ||
		canvas[curheight - 26][23] == (G << 3) ||
		canvas[curheight - 25][23] == (G << 3) ||
		canvas[curheight - 32][24] == (G << 3) ||
		canvas[curheight - 31][24] == (G << 3) ||
		canvas[curheight - 30][24] == (G << 3) ||
		canvas[curheight - 29][24] == (G << 3) ||
		canvas[curheight - 28][24] == (G << 3) ||
		canvas[curheight - 27][24] == (G << 3) ||
		canvas[curheight - 26][24] == (G << 3) ||
		canvas[curheight - 25][24] == (G << 3) ||
		canvas[curheight - 32][25] == (G << 3) ||
		canvas[curheight - 31][25] == (G << 3) ||
		canvas[curheight - 30][25] == (G << 3) ||
		canvas[curheight - 29][25] == (G << 3) ||
		canvas[curheight - 28][25] == (G << 3) ||
		canvas[curheight - 27][25] == (G << 3) ||
		canvas[curheight - 26][25] == (G << 3) ||
		canvas[curheight - 25][25] == (G << 3) ||
		canvas[curheight - 32][26] == (G << 3) ||
		canvas[curheight - 31][26] == (G << 3) ||
		canvas[curheight - 30][26] == (G << 3) ||
		canvas[curheight - 29][26] == (G << 3) ||
		canvas[curheight - 28][26] == (G << 3) ||
		canvas[curheight - 27][26] == (G << 3) ||
		canvas[curheight - 26][26] == (G << 3) ||
		canvas[curheight - 25][26] == (G << 3) ||
		canvas[curheight - 32][27] == (G << 3) ||
		canvas[curheight - 31][27] == (G << 3) ||
		canvas[curheight - 30][27] == (G << 3) ||
		canvas[curheight - 29][27] == (G << 3) ||
		canvas[curheight - 28][27] == (G << 3) ||
		canvas[curheight - 27][27] == (G << 3) ||
		canvas[curheight - 26][27] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)){
			makegameover = 1;
		}
	}

	if(curheight < ROW && curheight + 7 >= ROW){
		if(canvas[curheight][20] == G ||
		canvas[curheight][21] == G ||
		canvas[curheight][22] == G ||
		canvas[curheight][23] == G ||
		canvas[curheight][24] == G ||
		canvas[curheight][25] == G ||
		canvas[curheight][26] == G ||
		canvas[curheight][27] == G ||
		canvas[curheight - 25][20] == (G << 3) ||
		canvas[curheight - 25][21] == (G << 3) ||
		canvas[curheight - 25][22] == (G << 3) ||
		canvas[curheight - 25][23] == (G << 3) ||
		canvas[curheight - 25][24] == (G << 3) ||
		canvas[curheight - 25][25] == (G << 3) ||
		canvas[curheight - 25][26] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)){
			makegameover = 1;
		}
	}

	if(curheight + 7 < ROW){
		if(canvas[curheight][20] == G ||
		canvas[curheight][21] == G ||
		canvas[curheight][22] == G ||
		canvas[curheight][23] == G ||
		canvas[curheight][24] == G ||
		canvas[curheight][25] == G ||
		canvas[curheight][26] == G ||
		canvas[curheight][27] == G ||
		canvas[curheight + 1][20] == G ||
		canvas[curheight + 1][21] == G ||
		canvas[curheight + 1][22] == G ||
		canvas[curheight + 1][23] == G ||
		canvas[curheight + 1][24] == G ||
		canvas[curheight + 1][25] == G ||
		canvas[curheight + 1][26] == G ||
		canvas[curheight + 1][27] == G ||
		canvas[curheight + 2][20] == G ||
		canvas[curheight + 2][21] == G ||
		canvas[curheight + 2][22] == G ||
		canvas[curheight + 2][23] == G ||
		canvas[curheight + 2][24] == G ||
		canvas[curheight + 2][25] == G ||
		canvas[curheight + 2][26] == G ||
		canvas[curheight + 2][27] == G ||
		canvas[curheight + 3][20] == G ||
		canvas[curheight + 3][21] == G ||
		canvas[curheight + 3][22] == G ||
		canvas[curheight + 3][23] == G ||
		canvas[curheight + 3][24] == G ||
		canvas[curheight + 3][25] == G ||
		canvas[curheight + 3][26] == G ||
		canvas[curheight + 3][27] == G ||
		canvas[curheight + 4][20] == G ||
		canvas[curheight + 4][21] == G ||
		canvas[curheight + 4][22] == G ||
		canvas[curheight + 4][23] == G ||
		canvas[curheight + 4][24] == G ||
		canvas[curheight + 4][25] == G ||
		canvas[curheight + 4][26] == G ||
		canvas[curheight + 4][27] == G ||
		canvas[curheight + 5][20] == G ||
		canvas[curheight + 5][21] == G ||
		canvas[curheight + 5][22] == G ||
		canvas[curheight + 5][23] == G ||
		canvas[curheight + 5][24] == G ||
		canvas[curheight + 5][25] == G ||
		canvas[curheight + 5][26] == G ||
		canvas[curheight + 5][27] == G ||
		canvas[curheight + 6][20] == G ||
		canvas[curheight + 6][21] == G ||
		canvas[curheight + 6][22] == G ||
		canvas[curheight + 6][23] == G ||
		canvas[curheight + 6][24] == G ||
		canvas[curheight + 6][25] == G ||
		canvas[curheight + 6][26] == G ||
		canvas[curheight + 6][27] == G ||
		canvas[curheight + 7][20] == G ||
		canvas[curheight + 7][21] == G ||
		canvas[curheight + 7][22] == G ||
		canvas[curheight + 7][23] == G ||
		canvas[curheight + 7][24] == G ||
		canvas[curheight + 7][25] == G ||
		canvas[curheight + 7][26] == G ||
		canvas[curheight + 7][27] == G){
			makegameover = 1;
		}
	}

	/*
	if(curheight >= ROW){
		if(canvas[curheight - 32][20] == (G << 3) ||
		canvas[curheight - 32][21] == (G << 3) ||
		canvas[curheight - 32][22] == (G << 3) ||
		canvas[curheight - 32][23] == (G << 3) ||
		canvas[curheight - 32][24] == (G << 3) ||
		canvas[curheight - 32][25] == (G << 3) ||
		canvas[curheight - 32][26] == (G << 3) ||
		canvas[curheight - 32][27] == (G << 3)) {
			makegameover = 1;
		}
	}else {
		if(canvas[curheight][20] == G ||
		canvas[curheight][21] == G ||
		canvas[curheight][22] == G ||
		canvas[curheight][23] == G ||
		canvas[curheight][24] == G ||
		canvas[curheight][25] == G ||
		canvas[curheight][26] == G ||
		canvas[curheight][27] == G) {
			makegameover = 1;
		}
	}

	if(curheight + 7 >= ROW){
		if(canvas[curheight - 25][20] == (G << 3) ||
		canvas[curheight - 25][21] == (G << 3) ||
		canvas[curheight - 25][22] == (G << 3) ||
		canvas[curheight - 25][23] == (G << 3) ||
		canvas[curheight - 25][24] == (G << 3) ||
		canvas[curheight - 25][25] == (G << 3) ||
		canvas[curheight - 25][26] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)) {
			makegameover = 1;
		}
	}else {
		if(canvas[curheight + 7][20] == G ||
		canvas[curheight + 7][21] == G ||
		canvas[curheight + 7][22] == G ||
		canvas[curheight + 7][23] == G ||
		canvas[curheight + 7][24] == G ||
		canvas[curheight + 7][25] == G ||
		canvas[curheight + 7][26] == G ||
		canvas[curheight + 7][27] == G) {
			makegameover = 1;
		}
	}*/

	/*
	if(i <= 27 && i >= 20){
		if(curheight >= ROW){
			if(pipes_bot[a][curheight - 32][i] == G || pipes_bot[a][curheight - 25][i] == G){
				makegameover = 1;
			}
		}

		else if(curheight < ROW && curheight + 7 >= ROW){
			if(pipes_top[a][curheight][i] == G || pipes_bot[a][curheight - 25][i] == G){
				makegameover = 1;
			}
		}

		else if(curheight + 7 < ROW){
			if((pipes_top[a][curheight][i] == G) || (pipes_top[a][curheight + 7][i] == G)){
				makegameover = 1;
			}
		}
	}

	if(j <= 27 && j >= 20){
		if(curheight >= ROW){
			if(pipes_bot[b][curheight - 32][j] == G || pipes_bot[b][curheight - 25][j] == G){
				makegameover = 1;
			}
		}

		else if(curheight < ROW && curheight + 7 >= ROW){
			if(pipes_top[b][curheight][j] == G || pipes_bot[b][curheight - 25][j] == G){
				makegameover = 1;
			}
		}

		else if(curheight + 7 < ROW){
			if((pipes_top[b][curheight][j] == G) || (pipes_top[b][curheight + 7][j] == G)){
				makegameover = 1;
			}
		}
	}

	if(k <= 27 && k >= 20){
		if(curheight >= ROW){
			if(pipes_bot[c][curheight - 32][k] == G || pipes_bot[c][curheight - 25][k] == G){
				makegameover = 1;
			}
		}

		else if(curheight < ROW && curheight + 7 >= ROW){
			if(pipes_top[c][curheight][k] == G || pipes_bot[c][curheight - 25][k] == G){
				makegameover = 1;
			}
		}

		else if(curheight + 7 < ROW){
			if((pipes_top[c][curheight][k] == G) || (pipes_top[c][curheight + 7][k] == G)){
				makegameover = 1;
			}
		}
	}*/

	mask_canvas(curheight + 5, 20, height, width, bird[0]);
	mask_canvas(curheight, 20, height, width, bird[2]);

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

	/*
	if(curheight >= ROW){
		if(canvas[curheight - 32][20] == (G << 3) ||
		canvas[curheight - 31][20] == (G << 3) ||
		canvas[curheight - 30][20] == (G << 3) ||
		canvas[curheight - 29][20] == (G << 3) ||
		canvas[curheight - 28][20] == (G << 3) ||
		canvas[curheight - 27][20] == (G << 3) ||
		canvas[curheight - 26][20] == (G << 3) ||
		canvas[curheight - 25][20] == (G << 3) ||
		canvas[curheight - 32][27] == (G << 3) ||
		canvas[curheight - 31][27] == (G << 3) ||
		canvas[curheight - 30][27] == (G << 3) ||
		canvas[curheight - 29][27] == (G << 3) ||
		canvas[curheight - 28][27] == (G << 3) ||
		canvas[curheight - 27][27] == (G << 3) ||
		canvas[curheight - 26][27] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)){
			makegameover = 1;
		}
	}

	if(curheight < ROW && curheight + 7 >= ROW){
		if(canvas[curheight - 32][20] == G ||
		canvas[curheight - 31][20] == G ||
		canvas[curheight - 30][20] == G ||
		canvas[curheight - 29][20] == G ||
		canvas[curheight - 28][20] == G ||
		canvas[curheight - 27][20] == G ||
		canvas[curheight - 26][20] == G ||
		canvas[curheight - 25][20] == G ||
		canvas[curheight - 32][27] == (G << 3) ||
		canvas[curheight - 31][27] == (G << 3) ||
		canvas[curheight - 30][27] == (G << 3) ||
		canvas[curheight - 29][27] == (G << 3) ||
		canvas[curheight - 28][27] == (G << 3) ||
		canvas[curheight - 27][27] == (G << 3) ||
		canvas[curheight - 26][27] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)){
			makegameover = 1;
		}
	}

	if(curheight + 7 < ROW){
		if(canvas[curheight - 32][20] == (G << 3)||
		canvas[curheight - 31][20] == (G << 3) ||
		canvas[curheight - 30][20] == (G << 3) ||
		canvas[curheight - 29][20] == (G << 3) ||
		canvas[curheight - 28][20] == (G << 3) ||
		canvas[curheight - 27][20] == (G << 3) ||
		canvas[curheight - 26][20] == (G << 3) ||
		canvas[curheight - 25][20] == (G << 3) ||
		canvas[curheight - 32][27] == (G << 3) ||
		canvas[curheight - 31][27] == (G << 3) ||
		canvas[curheight - 30][27] == (G << 3) ||
		canvas[curheight - 29][27] == (G << 3) ||
		canvas[curheight - 28][27] == (G << 3) ||
		canvas[curheight - 27][27] == (G << 3) ||
		canvas[curheight - 26][27] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)){
			makegameover = 1;
		}
	}*/

	if(curheight + 7 >= ROW){
			if(canvas[curheight - 32][20] == (G << 3)||
			canvas[curheight - 31][20] == (G << 3) ||
			canvas[curheight - 30][20] == (G << 3) ||
			canvas[curheight - 29][20] == (G << 3) ||
			canvas[curheight - 28][20] == (G << 3) ||
			canvas[curheight - 27][20] == (G << 3) ||
			canvas[curheight - 26][20] == (G << 3) ||
			canvas[curheight - 25][20] == (G << 3) ||
			canvas[curheight - 32][21] == (G << 3) ||
			canvas[curheight - 31][21] == (G << 3) ||
			canvas[curheight - 30][21] == (G << 3) ||
			canvas[curheight - 29][21] == (G << 3) ||
			canvas[curheight - 28][21] == (G << 3) ||
			canvas[curheight - 27][21] == (G << 3) ||
			canvas[curheight - 26][21] == (G << 3) ||
			canvas[curheight - 25][21] == (G << 3) ||
			canvas[curheight - 32][22] == (G << 3) ||
			canvas[curheight - 31][22] == (G << 3) ||
			canvas[curheight - 30][22] == (G << 3) ||
			canvas[curheight - 29][22] == (G << 3) ||
			canvas[curheight - 28][22] == (G << 3) ||
			canvas[curheight - 27][22] == (G << 3) ||
			canvas[curheight - 26][22] == (G << 3) ||
			canvas[curheight - 25][22] == (G << 3) ||
			canvas[curheight - 32][23] == (G << 3) ||
			canvas[curheight - 31][23] == (G << 3) ||
			canvas[curheight - 30][23] == (G << 3) ||
			canvas[curheight - 29][23] == (G << 3) ||
			canvas[curheight - 28][23] == (G << 3) ||
			canvas[curheight - 27][23] == (G << 3) ||
			canvas[curheight - 26][23] == (G << 3) ||
			canvas[curheight - 25][23] == (G << 3) ||
			canvas[curheight - 32][24] == (G << 3) ||
			canvas[curheight - 31][24] == (G << 3) ||
			canvas[curheight - 30][24] == (G << 3) ||
			canvas[curheight - 29][24] == (G << 3) ||
			canvas[curheight - 28][24] == (G << 3) ||
			canvas[curheight - 27][24] == (G << 3) ||
			canvas[curheight - 26][24] == (G << 3) ||
			canvas[curheight - 25][24] == (G << 3) ||
			canvas[curheight - 32][25] == (G << 3) ||
			canvas[curheight - 31][25] == (G << 3) ||
			canvas[curheight - 30][25] == (G << 3) ||
			canvas[curheight - 29][25] == (G << 3) ||
			canvas[curheight - 28][25] == (G << 3) ||
			canvas[curheight - 27][25] == (G << 3) ||
			canvas[curheight - 26][25] == (G << 3) ||
			canvas[curheight - 25][25] == (G << 3) ||
			canvas[curheight - 32][26] == (G << 3) ||
			canvas[curheight - 31][26] == (G << 3) ||
			canvas[curheight - 30][26] == (G << 3) ||
			canvas[curheight - 29][26] == (G << 3) ||
			canvas[curheight - 28][26] == (G << 3) ||
			canvas[curheight - 27][26] == (G << 3) ||
			canvas[curheight - 26][26] == (G << 3) ||
			canvas[curheight - 25][26] == (G << 3) ||
			canvas[curheight - 32][27] == (G << 3) ||
			canvas[curheight - 31][27] == (G << 3) ||
			canvas[curheight - 30][27] == (G << 3) ||
			canvas[curheight - 29][27] == (G << 3) ||
			canvas[curheight - 28][27] == (G << 3) ||
			canvas[curheight - 27][27] == (G << 3) ||
			canvas[curheight - 26][27] == (G << 3) ||
			canvas[curheight - 25][27] == (G << 3)){
				makegameover = 1;
			}
		}

		if(curheight < ROW && curheight + 7 >= ROW){
			if(canvas[curheight][20] == G ||
			canvas[curheight][21] == G ||
			canvas[curheight][22] == G ||
			canvas[curheight][23] == G ||
			canvas[curheight][24] == G ||
			canvas[curheight][25] == G ||
			canvas[curheight][26] == G ||
			canvas[curheight][27] == G ||
			canvas[curheight - 25][20] == (G << 3) ||
			canvas[curheight - 25][21] == (G << 3) ||
			canvas[curheight - 25][22] == (G << 3) ||
			canvas[curheight - 25][23] == (G << 3) ||
			canvas[curheight - 25][24] == (G << 3) ||
			canvas[curheight - 25][25] == (G << 3) ||
			canvas[curheight - 25][26] == (G << 3) ||
			canvas[curheight - 25][27] == (G << 3)){
				makegameover = 1;
			}
		}

		if(curheight + 7 < ROW){
			if(canvas[curheight][20] == G ||
			canvas[curheight][21] == G ||
			canvas[curheight][22] == G ||
			canvas[curheight][23] == G ||
			canvas[curheight][24] == G ||
			canvas[curheight][25] == G ||
			canvas[curheight][26] == G ||
			canvas[curheight][27] == G ||
			canvas[curheight + 1][20] == G ||
			canvas[curheight + 1][21] == G ||
			canvas[curheight + 1][22] == G ||
			canvas[curheight + 1][23] == G ||
			canvas[curheight + 1][24] == G ||
			canvas[curheight + 1][25] == G ||
			canvas[curheight + 1][26] == G ||
			canvas[curheight + 1][27] == G ||
			canvas[curheight + 2][20] == G ||
			canvas[curheight + 2][21] == G ||
			canvas[curheight + 2][22] == G ||
			canvas[curheight + 2][23] == G ||
			canvas[curheight + 2][24] == G ||
			canvas[curheight + 2][25] == G ||
			canvas[curheight + 2][26] == G ||
			canvas[curheight + 2][27] == G ||
			canvas[curheight + 3][20] == G ||
			canvas[curheight + 3][21] == G ||
			canvas[curheight + 3][22] == G ||
			canvas[curheight + 3][23] == G ||
			canvas[curheight + 3][24] == G ||
			canvas[curheight + 3][25] == G ||
			canvas[curheight + 3][26] == G ||
			canvas[curheight + 3][27] == G ||
			canvas[curheight + 4][20] == G ||
			canvas[curheight + 4][21] == G ||
			canvas[curheight + 4][22] == G ||
			canvas[curheight + 4][23] == G ||
			canvas[curheight + 4][24] == G ||
			canvas[curheight + 4][25] == G ||
			canvas[curheight + 4][26] == G ||
			canvas[curheight + 4][27] == G ||
			canvas[curheight + 5][20] == G ||
			canvas[curheight + 5][21] == G ||
			canvas[curheight + 5][22] == G ||
			canvas[curheight + 5][23] == G ||
			canvas[curheight + 5][24] == G ||
			canvas[curheight + 5][25] == G ||
			canvas[curheight + 5][26] == G ||
			canvas[curheight + 5][27] == G ||
			canvas[curheight + 6][20] == G ||
			canvas[curheight + 6][21] == G ||
			canvas[curheight + 6][22] == G ||
			canvas[curheight + 6][23] == G ||
			canvas[curheight + 6][24] == G ||
			canvas[curheight + 6][25] == G ||
			canvas[curheight + 6][26] == G ||
			canvas[curheight + 6][27] == G ||
			canvas[curheight + 7][20] == G ||
			canvas[curheight + 7][21] == G ||
			canvas[curheight + 7][22] == G ||
			canvas[curheight + 7][23] == G ||
			canvas[curheight + 7][24] == G ||
			canvas[curheight + 7][25] == G ||
			canvas[curheight + 7][26] == G ||
			canvas[curheight + 7][27] == G){
				makegameover = 1;
			}
		}

	/*
	if(curheight >= ROW){
		if(canvas[curheight - 32][20] == (G << 3) ||
		canvas[curheight - 32][21] == (G << 3) ||
		canvas[curheight - 32][22] == (G << 3) ||
		canvas[curheight - 32][23] == (G << 3) ||
		canvas[curheight - 32][24] == (G << 3) ||
		canvas[curheight - 32][25] == (G << 3) ||
		canvas[curheight - 32][26] == (G << 3) ||
		canvas[curheight - 32][27] == (G << 3)) {
			makegameover = 1;
		}
	}else {
		if(canvas[curheight][20] == G ||
		canvas[curheight][21] == G ||
		canvas[curheight][22] == G ||
		canvas[curheight][23] == G ||
		canvas[curheight][24] == G ||
		canvas[curheight][25] == G ||
		canvas[curheight][26] == G ||
		canvas[curheight][27] == G) {
			makegameover = 1;
		}
	}

	if(curheight + 7 >= ROW){
		if(canvas[curheight - 25][20] == (G << 3) ||
		canvas[curheight - 25][21] == (G << 3) ||
		canvas[curheight - 25][22] == (G << 3) ||
		canvas[curheight - 25][23] == (G << 3) ||
		canvas[curheight - 25][24] == (G << 3) ||
		canvas[curheight - 25][25] == (G << 3) ||
		canvas[curheight - 25][26] == (G << 3) ||
		canvas[curheight - 25][27] == (G << 3)) {
			makegameover = 1;
		}
	}else {
		if(canvas[curheight + 7][20] == G ||
		canvas[curheight + 7][21] == G ||
		canvas[curheight + 7][22] == G ||
		canvas[curheight + 7][23] == G ||
		canvas[curheight + 7][24] == G ||
		canvas[curheight + 7][25] == G ||
		canvas[curheight + 7][26] == G ||
		canvas[curheight + 7][27] == G) {
			makegameover = 1;
		}
	}*/

	//|| (j <= 27 && j >= 20) || (k <= 27 && k >= 20)){
	/*
	if(i <= 27 && i >= 20){
		if(curheight >= ROW){
			if(pipes_bot[a][curheight - 32][i] == G || pipes_bot[a][curheight - 25][i] == G){
				makegameover = 1;
			}
		}

		else if(curheight < ROW && curheight + 7 >= ROW){
			if(pipes_top[a][curheight][i] == G || pipes_bot[a][curheight - 25][i] == G){
				makegameover = 1;
			}
		}

		else if(curheight + 7 < ROW){
			if((pipes_top[a][curheight][i] == G) || (pipes_top[a][curheight + 7][i] == G)){
				makegameover = 1;
			}
		}
	}

	if(j <= 27 && j >= 20){
		if(curheight >= ROW){
			if(pipes_bot[b][curheight - 32][j] == G || pipes_bot[b][curheight - 25][j] == G){
				makegameover = 1;
			}
		}

		else if(curheight < ROW && curheight + 7 >= ROW){
			if(pipes_top[b][curheight][j] == G || pipes_bot[b][curheight - 25][j] == G){
				makegameover = 1;
			}
		}

		else if(curheight + 7 < ROW){
			if((pipes_top[b][curheight][j] == G) || (pipes_top[b][curheight + 7][j] == G)){
				makegameover = 1;
			}
		}
	}

	if(k <= 27 && k >= 20){
		if(curheight >= ROW){
			if(pipes_bot[c][curheight - 32][k] == G || pipes_bot[c][curheight - 25][k] == G){
				makegameover = 1;
			}
		}

		else if(curheight < ROW && curheight + 7 >= ROW){
			if(pipes_top[c][curheight][k] == G || pipes_bot[c][curheight - 25][k] == G){
				makegameover = 1;
			}
		}

		else if(curheight + 7 < ROW){
			if((pipes_top[c][curheight][k] == G) || (pipes_top[c][curheight + 7][k] == G)){
				makegameover = 1;
			}
		}
	}*/

	mask_canvas(curheight - 1, 20, height, width, bird[0]);
	mask_canvas(curheight, 20, height, width, bird[1]);

	if(i == 16 || j == 16 || k == 16){
		score++;
	}

	if ((TIM3->SR & TIM_SR_UIF) != 0) {
		TIM3->SR &= ~TIM_SR_UIF;
	}
	TIM3->CR1 |= TIM_CR1_CEN;
}

void gameover(){
	EXTI->IMR &= ~EXTI_IMR_MR8;
	TIM3->CR1 &= ~TIM_CR1_CEN;
	TIM2->CR1 &= ~TIM_CR1_CEN;
	TIM6->CR1 &= ~TIM_CR1_CEN;
	TIM15->CR1 &= ~TIM_CR1_CEN;

	while(1){
		draw_gameover();
		generate_image();
	}
}

void start_game() {
	clear_display();

	init_wavetable();
	init_timer6();
	init_timer15();
	init_timer2();
	init_timer3();

	while (!isgameover) {
		lcd_display_score(score);
		if(curheight >= 50){
			isgameover = 1;
		}
	}

	gameover();
}
