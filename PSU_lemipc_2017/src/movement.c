/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** movement
*/

#include "lemipc.h"

void	go_to_x(player_t *player)
{
	if (player->pos_x < player->enemy_pos_x
	&& player->segment[(player->pos_y * MAP_X) + player->pos_x + 1]
	== '0') {
		player->pos_x++;
		write_player_pos(player);
		return;
	} else if (player->pos_x > player->enemy_pos_x
	&& player->segment[(player->pos_y * MAP_X) + player->pos_x - 1]
	== '0') {
		player->pos_x--;
		write_player_pos(player);
		return;
	}
}

void	go_to_y(player_t *player)
{
	if (player->pos_y > player->enemy_pos_y
	&& player->segment[((player->pos_y - 1) * MAP_X) + player->pos_x]
	== '0') {
		player->pos_y--;
		write_player_pos(player);
		return;
	}
	else if (player->pos_y < player->enemy_pos_y
	&& player->segment[((player->pos_y + 1) * MAP_X) + player->pos_x]
	== '0') {
		player->pos_y++;
		write_player_pos(player);
		return;
	}
}

void	go_to_enemy(player_t *player)
{
	if (player->pos_x == player->prev_pos_x
	&& player->prev_pos_y == player->pos_y) {
		unstuck(player);
	} else {
		int r = rand() % 2;
		player->prev_pos_x = player->pos_x;
		player->prev_pos_y = player->pos_y;
		if (r == 0 && player->pos_x <= MAP_X && player->pos_x >= 0)
			go_to_x(player);
		if (r == 1 && player->pos_y <= MAP_X && player->pos_y >= 0)
			go_to_y(player);
	}
}

int	unstuck_with_rand(player_t *player, int rand)
{
	if (rand == 2 && player->pos_x <= MAP_X) {
		if (player->segment[(player->pos_y * MAP_X)
		+ player->pos_x + 1] == '0') {
			player->pos_x++;
			write_player_pos(player);
		}
		return (1);
	}
	if (rand == 3 && player->pos_x - 1 >= 0) {
		if (player->segment[(player->pos_y * MAP_X)
		+ player->pos_x - 1] == '0') {
			player->pos_x--;
			write_player_pos(player);
		}
		return (1);
	}
	return (0);
}

void	unstuck(player_t *player)
{
	int r = rand() % 4;

	if (r == 0 && player->pos_y - 1 >= 0) {
		if (player->segment[((player->pos_y - 1) * MAP_X)
		+ player->pos_x] == '0') {
			player->pos_y--;
			write_player_pos(player);
		}
		return;
	}
	if (r == 1 && player->pos_y + 1 <= MAP_X) {
		if (player->segment[((player->pos_y + 1) * MAP_X)
		+ player->pos_x] == '0') {
			player->pos_y++;
			write_player_pos(player);
		}
		return;
	}
	if (unstuck_with_rand(player, r) == 1)
		return;
}
