/*
** EPITECH PROJECT, 2018
** CPP pool day2
** File description:
** ex02 tab to 2tab
*/

#include <stdlib.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
	int a = 0;

	*res = malloc(sizeof(int *) * (length + 1));
	if (*res == NULL)
		return;
	for (int x = 0; x < length; x++) {
		(*res)[x] = malloc(sizeof(int) * (width + 1));
		if ((*res)[x] == NULL)
			return;
		for (int y = 0; y < width; y++) {
			(*res)[x][y] = tab[a];
			a++;
		}
	}
}