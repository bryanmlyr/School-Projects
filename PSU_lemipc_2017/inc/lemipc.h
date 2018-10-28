/*
** EPITECH PROJECT, 2018
** Header
** File description:
** Lemipc
*/

#ifndef LEMIPC_H_
#define LEMIPC_H_

#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAP_X 32
#define MAP_SIZE 32 * 32 + 1

enum	master
{
	YES,
	NO
};

typedef	struct	player_s
{
	int	prev_pos_x;
	int	prev_pos_y;
	int	pos_x;
	int	pos_y;

	int	enemy_pos_x;
	int	enemy_pos_y;

	int	team_number;

	int	game_master;

	int	shmid;
	int	semid;
	int	msgid;
	key_t	key;

	char	*segment;
}player_t;

typedef struct	msg_s
{
	long	team_number;
	char	msg[128];
}	msg_t;

void	get_shmid(player_t *);
void	*get_segment(player_t *);
void	write_segment(void *inject, player_t *);
void	remove_ipc_shm(player_t *);

void	get_semid(player_t *);
void	sem_dec(player_t *);
void	sem_inc(player_t *);
int	sem_get(player_t *);
void	remove_ipc_sem(player_t *);

void	get_msgid(player_t *);
void	print_msg(player_t *);
void	send_msg_pos(player_t *);

void	go_to_y(player_t *);
void	go_to_x(player_t *);
void	go_to_enemy(player_t *);
int     unstuck_with_rand(player_t *, int);
void    unstuck(player_t *);

void	remove_ipc_msg(player_t *);

void	print_map(char*);
void	write_player_pos(player_t *);

int     is_enemy(player_t *, char pos, int pos_y, int pos_x);
void    find_enemy(player_t *);

int     game_is_valid(player_t *);
int     game_is_finished(player_t *);

#endif /* !LEMIPC_H_ */
