/*
** EPITECH PROJECT, 2018
** add
** File description:
** ex04
*/

#include "castmania.h"
#include <stdio.h>

int	my_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

int	normal_add(int a, int b)
{
	return (a + b);
}

int	absolute_add(int a, int b)
{
	return (my_abs(a) + my_abs(b));
}

void	exec_add(add_t *operation)
{
	integer_op_t args = (integer_op_t)operation->add_op;
	if (operation->add_type == NORMAL) {
		args.res = normal_add(args.a, args.b);
	}
	if (operation->add_type == ABSOLUTE) {
		args.res = absolute_add(args.a, args.b);
	}
	operation->add_op = args;
}