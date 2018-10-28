/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** MessagesQ
*/

#include "lemipc.h"

void	get_msgid(player_t *player)
{
	player->msgid = msgget(player->key, 0600);
	if (player->msgid == -1)
		player->msgid = msgget(player->key,
		0600 | IPC_CREAT | IPC_NOWAIT);
}

void	send_msg_pos(player_t *player)
{
	msg_t	new_msg;

	new_msg.team_number = (long)player->team_number;
	sprintf(new_msg.msg, "%d", player->pos_x * player->pos_y);
	msgsnd(player->msgid, &new_msg, sizeof(new_msg), IPC_NOWAIT);
}

void	print_msg(player_t *player)
{
	msg_t	msg;

	msgrcv(player->msgid, &msg, sizeof(msg), 1, IPC_NOWAIT);
	msgrcv(player->msgid, &msg, sizeof(msg), 2, IPC_NOWAIT);
}

void	remove_ipc_msg(player_t *player)
{
	if (player->game_master == YES)
		msgctl(player->msgid, IPC_RMID, 0);
}
