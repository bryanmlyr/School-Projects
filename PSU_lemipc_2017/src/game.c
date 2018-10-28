/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** game
*/

#include "lemipc.h"

int     game_is_valid(player_t *player)
{
	int     nb_team_1 = 0;
	int     nb_team_2 = 0;

	for (int x = 0; x < MAP_SIZE; x++) {
		if (player->segment[x] == '1')
			nb_team_1++;
		if (player->segment[x] == '2')
			nb_team_2++;
	}
	if (nb_team_1 >= 2 && nb_team_2 >= 2)
		return (1);
	return (0);
}

int     game_is_finished(player_t *player)
{
	unsigned int    team_1 = 0;
	unsigned int    team_2 = 0;

	for (int x = 0; x < MAP_SIZE; x++) {
		if (player->segment[x] == '1')
			team_1 = 1;
		if (player->segment[x] == '2')
			team_2 = 1;
	}
	if (team_1 + team_2 == 1)
		return (1);
	return (0);
}
