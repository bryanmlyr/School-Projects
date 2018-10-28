/*
** EPITECH PROJECT, 2018
** Lemipc
** File description:
** main
*/

#include "lemipc.h"

int	dead(player_t *player)
{
	int	ret = 0;
	int	x = player->pos_x;
	int	y = player->pos_y;

	if (y > 0 && player->segment[((y - 1) * MAP_X) + x] != '0'
	&& player->segment[((y - 1) * MAP_X) + x] != player->team_number + 48)
		ret++;
	if (x > 0 && player->segment[((y) * MAP_X) + x - 1] != '0'
	&& player->segment[((y) * MAP_X) + x - 1] != player->team_number + 48)
		ret++;
	if (x < MAP_X && player->segment[((y) * MAP_X) + x + 1] != '0' &&
	player->segment[((y) * MAP_X) + x + 1] != player->team_number + 48)
		ret++;
	if (y < MAP_X && player->segment[((y + 1) * MAP_X) + x] != '0'
	&& player->segment[((y + 1) * MAP_X) + x] != player->team_number + 48)
		ret++;
	if (ret >= 2)
		player->segment[(y * MAP_X) + x] = '0';
	return (ret >= 2 ? 1 : 0);
}

player_t	init_struct(player_t player, char **av)
{
	player.key = ftok(av[1], 42);
	player.team_number = atoi(av[2]);
	get_shmid(&player);
	get_semid(&player);
	get_msgid(&player);
	srand(time(NULL) * getpid());
	player.segment = get_segment(&player);
	player.pos_x = rand() % MAP_X;
	player.pos_y = rand() % MAP_X;
	player.prev_pos_x = player.pos_x;
	player.prev_pos_y = player.pos_y;

	sem_dec(&player);
	write_player_pos(&player);
	sem_inc(&player);
	return (player);
}

player_t	start_game(player_t player)
{
	usleep(100000);
	sem_dec(&player);
	find_enemy(&player);
	go_to_enemy(&player);
	send_msg_pos(&player);
	print_msg(&player);
	return (player);
}

player_t	loop_game(player_t player)
{
	while (1) {
		player = start_game(player);
		if (dead(&player) == 1) {
			sem_inc(&player);
			break;
		}
		if (player.game_master == YES)
			print_map(player.segment);
		if (game_is_finished(&player) == 1) {
			print_map(player.segment);
			sem_inc(&player);
			break;
		}
		sem_inc(&player);
	}
	return (player);
}

int	main(int ac, char **av)
{
	if (ac != 3 || (strcmp(av[2], "2") != 0 && strcmp(av[2], "1") != 0))
		return (84);
	player_t	player;

	player = init_struct(player, av);
	while (game_is_valid(&player) != 1);
	player = loop_game(player);
	while (player.game_master == YES && game_is_finished(&player) == 0) {
		usleep(100000);
		print_map(player.segment);
	}
	if (game_is_finished(&player) == 1 && player.game_master == YES) {
		sleep(1);
		printf("Game is finished !\nPress enter !\n");
	}
	shmdt(player.segment);
	remove_ipc_msg(&player);
	remove_ipc_shm(&player);
	remove_ipc_sem(&player);
	return (0);
}
