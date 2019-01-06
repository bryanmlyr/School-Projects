/*
** EPITECH PROJECT, 2018
** menger
** File description:
** menger
*/

#include "menger.h"

void    menger_rec(int *d)
{
	if (d[4] > 0) {
		printf ("%.3d %.3d %.3d\n", ((d[0] + 2 * d[2] / 3) -
		(d[0] + d[2] / 3)), (d[1] + d[3] / 3), (d[0] + d[2] / 3));
		menger_rec((int[5]){d[0], d[1], d[2] / 3, d[3] / 3
		, d[4] - 1});
		menger_rec((int[5]){d[0] + d[2] / 3, d[1], d[2] / 3, d[3] / 3
		, d[4] - 1});
		menger_rec((int[5]){d[0] + 2 * d[2] / 3, d[1], d[2] / 3
		, d[3] / 3, d[4] - 1});
		menger_rec((int[5]){d[0], d[1] + d[3] / 3, d[2] / 3, d[3] / 3
		, d[4] - 1});
		menger_rec((int[5]){d[0] + 2 * d[2] / 3, d[1] + d[3] / 3
		, d[2] / 3, d[3] / 3, d[4] - 1});
		menger_rec((int[5]){d[0], d[1] + 2 * d[3] / 3, d[2] / 3
		, d[3] / 3, d[4] - 1});
		menger_rec((int[5]){d[0] + d[2] / 3, d[1] + 2 * d[3] / 3
		, d[2] / 3, d[3] / 3, d[4] - 1});
		menger_rec((int[5]){d[0] + 2 * d[2] / 3, d[1] + 2 * d[3] / 3
		, d[2] / 3, d[3] / 3, d[4] - 1});
	}
}