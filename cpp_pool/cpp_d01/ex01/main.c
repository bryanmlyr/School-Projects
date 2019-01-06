/*
** EPITECH PROJECT, 2018
** main
** File description:
** menger sponge
*/

#include "menger.h"

int     my_getnbr(char *str)
{
	int neg = 1, nb = 0, x = 0;

	while (str[x] == '-') {
		neg *= -1;
		x++;
	}
	while (str[x]) {
		nb = nb * 10 + (str[x] - 48);
		x++;
	}
	return (nb * neg);
}

int     main(int ac, char **av)
{
	if (ac != 3)
		return (84);
	if (my_getnbr(av[1]) <= 0 || my_getnbr(av[1]) % 3 != 0)
		return (84);
	int x = my_getnbr(av[1]);

	menger_rec((int[5]){0, 0, x, x, my_getnbr(av[2])});
	return (0);
}