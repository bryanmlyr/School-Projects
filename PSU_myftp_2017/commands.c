/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** commands
*/

#include "server.h"

void	parse_cmd(char *cmd, char *argument, t_system *server, int x)
{
	if (argument)
		printf("cmd:%sargument:%s\n", cmd, argument);
	if (x >= 2 && x != QUIT && server->logged == false)
		dprintf(server->client.cmd_socket,
		"530 Please login with USER and PASS.\r\n");
	else
		server->cmds[x].cmd_function(server, argument);
	if (!argument)
		free(argument);
}

void	do_command(char *cmd, t_system *server)
{
	char *argument = strrchr(cmd, ' ');
	unsigned int x;

	if (argument) {
		argument = epur_str(argument);
		argument += 1;
	}
	for (x = 0; x != 14; x++)
		if (strncmp(cmd, server->cmds[x].cmd_pattern,
		strlen(server->cmds[x].cmd_pattern)) == 0) {
			parse_cmd(cmd, argument, server, x);
			return;
		}
	if (x == 14)
		dprintf(server->client.cmd_socket, "500 Unkown command.\r\n");
}