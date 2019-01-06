/*
** EPITECH PROJECT, 2018
** ex03
** File description:
** ex03
*/

#include <string.h>
#include <stdio.h>
#include "func_ptr.h"

void	print_normal(char *str)
{
	printf("%s\n", str);
}

void	print_reverse(char *str)
{
	int x = strlen(str) - 1;

	while (x > -1) {
		printf("%c", str[x]);
		x--;
	}
	printf("\n");
}

void	print_upper(char *str)
{
	int x = 0;

	while (str[x]) {
		if (str[x] >= 97 && str[x] <= 122)
			printf("%c", str[x] - 32);
		else
			printf("%c", str[x]);
		x++;
	}
	printf("\n");
}

void	print_42(char *str)
{
	str = "42";
	printf("%s\n", str);
}

void	do_action(action_t action, char *str)
{
	void	(*tbl_fn[4])(char *);

	tbl_fn[PRINT_NORMAL] = print_normal;
	tbl_fn[PRINT_REVERSE] = print_reverse;
	tbl_fn[PRINT_UPPER] = print_upper;
	tbl_fn[PRINT_42] = print_42;
	tbl_fn[action](str);
}