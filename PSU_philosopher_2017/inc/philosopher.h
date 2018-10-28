/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** header
*/

#ifndef PHILOSOPHER_H_
#define PHILOSOPHER_H_

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "extern.h"

enum chopstick_status_e
{
	YES,
	NO
};

typedef	struct		chopstick_s
{
	unsigned int	chopstick_id;
	int		chopstick_taken;
	pthread_mutex_t	mutex;
} chopstick_t;

typedef	struct		philosopher_s
{
	unsigned int	eat_counter;
	chopstick_t	*left;
	chopstick_t	*right;
	unsigned int	max_eat;
} philosopher_t;

typedef	struct		table_s
{
	pthread_t	*philos_hearts;
	chopstick_t	*chops;
	philosopher_t	*philos;
} table_t;

int	sit_on_table(table_t *, size_t);
void	*run_philo(void *);
void	think(void *);
void	eat(void *);
void	rest(void);
int	check_args(int, char **);

#endif /* !PHILOSOPHER_H_ */
