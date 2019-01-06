/*
** EPITECH PROJECT, 2018
** div
** File description:
** div
*/

#include "castmania.h"
#include <stdio.h>

int	integer_div(int a, int b)
{
	if (b == 0)
		return (0);
	return (a / b);
}

float	decimale_div(int a, int b)
{
	float ret = 0;

	if (b == 0)
		return (0);
	ret = a / b;
	return (ret);
}

void	exec_div(div_t *operation)
{
	if (operation->div_type == INTEGER) {
		integer_op_t *args = (integer_op_t *)operation->div_op;
		args->res = integer_div(args->a, args->b);
		operation->div_op = args;
	}
	if (operation->div_type == DECIMALE) {
		decimale_op_t *args = (decimale_op_t *)operation->div_op;
		args->res = decimale_div(args->a, args->b);
		operation->div_op = args;
	}
}