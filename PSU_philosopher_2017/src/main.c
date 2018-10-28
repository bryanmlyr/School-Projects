/*
** EPITECH PROJECT, 2018
** main
** File description:
** Je suis un philosophe et toi ?
*/

#include "philosopher.h"

chopstick_t		*create_chopsticks(size_t nb)
{
	chopstick_t 	*ret = malloc(sizeof(chopstick_t) * nb);
	unsigned int 	x = 0;

	if (!ret)
		exit(84);
	for (x = 0; x < nb; x++) {
		ret[x].chopstick_id = x;
		ret[x].chopstick_taken = NO;
		if (pthread_mutex_init(&ret[x].mutex, NULL) == -1)
			exit(84);
	}
	return (ret);
}

philosopher_t	*create_philos(size_t nb, chopstick_t *chops, size_t max_eat)
{
	philosopher_t	*ret = malloc(sizeof(philosopher_t) * nb);
	unsigned int	x = 0;

	if (!ret)
		exit(84);
	for (x = 0; x < nb - 1; x++) {
		ret[x].eat_counter = 0;
		ret[x].left = &chops[x];
		ret[x].right = &chops[x + 1];
		ret[x].max_eat = max_eat;
	}
	ret[x].eat_counter = 0;
	ret[x].left = &chops[x];
	ret[x].right = &chops[0];
	ret[x].max_eat = max_eat;
	return (ret);
}

table_t	gen_table(size_t nb_philos, size_t max_eat)
{
	table_t	ret;

	ret.chops = create_chopsticks(nb_philos);
	ret.philos_hearts = malloc(sizeof(pthread_t) * nb_philos);
	if (!ret.philos_hearts)
		exit(84);
	ret.philos = create_philos(nb_philos, ret.chops, max_eat);
	return (ret);
}

int	main(int ac, char **av)
{
	if (check_args(ac, av) == -1)
		return (84);
	RCFStartup(ac, av);
	unsigned int	nb_philos = atoi(av[2]);
	unsigned int	max_eat = atoi(av[4]);
	table_t		table = gen_table(nb_philos, max_eat);

	if (sit_on_table(&table, nb_philos) == 84)
		return (84);
	free(table.philos);
	free(table.philos_hearts);
	free(table.chops);
	RCFCleanup();
	return (0);
}
