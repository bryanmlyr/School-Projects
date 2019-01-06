/*
** EPITECH PROJECT, 2018
** ex03
** File description:
** src
*/

#include "drawing.h"

void  draw_square(uint32_t **img, point_t *origin, size_t size, uint32_t color)
{
	unsigned int x, y;

	for (x = origin->x; x < origin->x + size; x++) {
		for (y = origin->y; y < origin->y + size; y++) {
			img[x][y] = color;
		}
	}
}