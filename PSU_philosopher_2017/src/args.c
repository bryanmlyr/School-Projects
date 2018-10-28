/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** args
*/

#include "philosopher.h"

int	help(void)
{
	printf("USAGE\n\t   ./philo -p nbr_p -e nbr_e\n\nDESCRIPTION\n\t   ");
	printf("-p nbr_p  number of philosophers\n\t   ");
	printf("-e nbr_e  maximum number times a philosopher eats before");
	printf(" exiting the program\n");
	return (-1);
}

int	is_pos_digit(char *s)
{
	for (size_t x = 0; s[x]; x++) {
		if (!(s[x] >= '0' && s[x] <= '9'))
			return (-1);
	}
	return (0);
}

int	check_values(char **av)
{
	if (strcmp(av[1], "-p") != 0 && strcmp(av[3], "-e") != 0) {
		dprintf(2, "Undefined args\n");
		return (-1);
	}
	if (is_pos_digit(av[2]) == -1 || is_pos_digit(av[4]) == -1) {
		dprintf(2, "Strange numbers\n");
		return (-1);
	}
	if (atoi(av[2]) <= 1 || atoi(av[4]) == 0) {
		dprintf(2, "You need to put a positive number\n");
		return (-1);
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "--help") == 0)
		return (help());
	else if (ac == 5)
		return (check_values(av));
	else
		return (-1);
}