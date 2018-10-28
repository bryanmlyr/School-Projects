/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** enemy
*/

#include "lemipc.h"

int	is_enemy(player_t *player, char pos, int pos_y, int pos_x)
{
	if (pos_y >= 0 && pos_y <= MAP_X && pos_x >= 0 && pos_x <= MAP_X
	&& pos != '0' && pos != player->team_number + 48) {
		player->enemy_pos_x = pos_x;
		player->enemy_pos_y = pos_y;
		return (1);
	}
	return (0);
}

void	find_enemy(player_t *player)
{
	for (int x = 0; x < MAP_X; x++) {
		for (int y = 0; y < MAP_X; y++) {
			if (player->segment[(x * MAP_X) + y]
			!= player->team_number + 48
			&& player->segment[(x * MAP_X) + y] != '0') {
				player->enemy_pos_x = y;
				player->enemy_pos_y = x;
				return;
			}
		}
	}
}
