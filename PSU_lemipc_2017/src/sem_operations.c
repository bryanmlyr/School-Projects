/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Semaphores Lib
*/

#include "lemipc.h"

void	get_semid(player_t *player)
{
	player->semid = semget(player->key, 1, 0600);
	if (player->semid == -1) {
		player->semid = semget(player->key, 1, 0600 | IPC_CREAT);
		semctl(player->semid, 0, SETVAL, 1);
	}
}

void	sem_dec(player_t *player)
{
	struct sembuf sem;

	sem.sem_flg = 0;
	sem.sem_num = 0;
	sem.sem_op = -1;
	semop(player->semid, &sem, 1);
}

void	sem_inc(player_t *player)
{
	struct sembuf sem;

	sem.sem_flg = 0;
	sem.sem_num = 0;
	sem.sem_op = 1;
	semop(player->semid, &sem, 1);
}

int	sem_get(player_t *player)
{
	return (semctl(player->semid, 0, GETVAL));
}

void	remove_ipc_sem(player_t *player)
{
	if (player->game_master == YES)
		semctl(player->semid, IPC_RMID, 0);
}