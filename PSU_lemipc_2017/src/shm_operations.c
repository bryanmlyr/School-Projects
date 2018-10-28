/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Shared Memory Lib
*/

#include "lemipc.h"

void	get_shmid(player_t *player)
{
	player->shmid = shmget(player->key, MAP_SIZE, 0600);
	player->game_master = NO;
	if (player->shmid == -1) {
		player->shmid = shmget(player->key, MAP_SIZE, 0600 | IPC_CREAT);
		player->game_master = YES;
		char *map = malloc(sizeof(char) * MAP_SIZE);
		map = memset(map, '\0', MAP_SIZE);
		map = memset(map, '0', MAP_SIZE - 1);
		write_segment(map, player);
	}
}

void	*get_segment(player_t *player)
{
	void	*ret;
	if (player->shmid == -1)
		player->segment = NULL;
	ret = shmat(player->shmid, NULL, 0);
	player->segment = ret;
	return (ret);
}

void	write_segment(void *inject, player_t *player)
{
	void *data = get_segment(player);

	memcpy(data, inject, MAP_SIZE);
	shmdt(data);
}

void	remove_ipc_shm(player_t *player)
{
	if (player->game_master == YES)
		shmctl(player->shmid, IPC_RMID, NULL);
}