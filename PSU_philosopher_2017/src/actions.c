/*
** EPITECH PROJECT, 2018
** Philosophers
** File description:
** philosopher's actions
*/

#include "philosopher.h"

void	rest(void)
{
	lphilo_sleep();
}

void	eat(void *philosopher)
{
	philosopher_t	*p = (philosopher_t *)philosopher;

	while (p->left->chopstick_taken == YES
	&& p->right->chopstick_taken == YES);
	while (pthread_mutex_trylock(&p->left->mutex) == -1);
	lphilo_take_chopstick(&p->left->mutex);
	p->left->chopstick_taken = YES;
	while (pthread_mutex_trylock(&p->right->mutex) == -1);
	lphilo_take_chopstick(&p->right->mutex);
	lphilo_eat();
	p->eat_counter++;
	p->right->chopstick_taken = YES;
	pthread_mutex_unlock(&p->left->mutex);
	lphilo_release_chopstick(&p->left->mutex);
	pthread_mutex_unlock(&p->right->mutex);
	lphilo_release_chopstick(&p->right->mutex);
	p->right->chopstick_taken = NO;
	p->left->chopstick_taken = NO;
}

void	think(void *philosopher)
{
	philosopher_t	*p = (philosopher_t *)philosopher;

	while (p->left->chopstick_taken == YES ||
	p->right->chopstick_taken == YES);
	if (p->left->chopstick_taken != YES) {
		while (pthread_mutex_trylock(&p->left->mutex) == -1);
		lphilo_take_chopstick(&p->left->mutex);
		lphilo_think();
		pthread_mutex_unlock(&p->left->mutex);
		lphilo_release_chopstick(&p->left->mutex);
	} else if (p->right->chopstick_taken != YES) {
		while (pthread_mutex_trylock(&p->right->mutex) == -1);
		lphilo_take_chopstick(&p->right->mutex);
		lphilo_think();
		pthread_mutex_unlock(&p->right->mutex);
		lphilo_release_chopstick(&p->right->mutex);
	}
}

void	*run_philo(void *p)
{
	if (!p)
		exit(84);
	unsigned int max_eat = ((philosopher_t *)p)->max_eat;

	for (size_t x = 0; x < max_eat; x++) {
		think(p);
		eat(p);
		usleep(500);
		rest();
		usleep(500);
	}
	RCFCleanup();
	_exit(0);
	return (p);
}

int	sit_on_table(table_t *tbl, size_t nb_philos)
{
	size_t x = 0;

	for (x = 0; x < nb_philos; x++)
		if (pthread_create(&tbl->philos_hearts[x], NULL, run_philo,
		(void *)&tbl->philos[x])) {
			dprintf(2, "ERROR: Failed to create ");
			dprintf(2, "thread number: %ld.\n", x + 1);
			_exit(84);
		}
	for (size_t y = 0; y < x; y++)
		if (pthread_join(tbl->philos_hearts[y], NULL) != 0)
			return (84);
	return (0);
}
