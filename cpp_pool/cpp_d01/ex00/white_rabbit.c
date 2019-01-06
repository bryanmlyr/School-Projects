/*
** EPITECH PROJECT, 2018
** Piscine CPP Jour 1
** File description:
** ex00 White Rabbit
*/

#include <stdio.h>
#include <stdlib.h>

int     follow_the_white_rabbit(void)
{
	int sum = 0, rd = 0;

	while ((rd != 37 && rd != 1) && sum < 397) {
		rd = (random() % 37) + 1;
		sum += rd;
		switch (rd) {
			case 4: case 5: case 6: case 17: case 28:
			case 18: case 19: case 20: case 21:
				printf("left\n");
				break;
			case 13: case 34: case 35: case 36: printf("right\n");
				break;
			case 10: case 15: case 23: printf("forward\n");
				break;
			case 8: case 16: case 24: case 32: case 26:
				printf("backward\n");
				break;
		}
	}
	printf("RABBIT!!!\n");
	return (sum);
}