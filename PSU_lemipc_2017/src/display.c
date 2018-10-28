/*
** EPITECH PROJECT, 2018
** Lemipc
** File description:
** display
*/

#include "lemipc.h"

void	print_map(char *map)
{
	printf("\n--------------------------------\n");
	for (unsigned int x = 0; x < strlen(map); x++) {
		if (x % MAP_X == 0 && x != 0)
			printf("\n");
		if (map[x] == '1')
			printf("\x1b[31m%c\x1b[0m", map[x]);
		else if (map[x] == '2')
			printf("\x1b[34m%c\x1b[0m", map[x]);
		else
			printf("%c", map[x]);
	}
	printf("\n--------------------------------\n");
}

void	write_player_pos(player_t *player)
{
	player->segment[(player->prev_pos_y * MAP_X) + player->prev_pos_x]
		= '0';
	player->segment[(player->pos_y * MAP_X) + player->pos_x]
		= player->team_number + 48;
}
