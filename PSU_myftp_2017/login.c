/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** login
*/

#include "server.h"

void	user(t_system *serv, char *argument)
{
	if (argument == NULL || strlen(argument) == 0)
		dprintf(serv->client.cmd_socket, "530 Permission denied.\r\n");
	else if (serv->logged == true)
		dprintf(serv->client.cmd_socket,
		"530 Can't change from guest user.\r\n");
	else {
		serv->username = strdup(argument);
		dprintf(serv->client.cmd_socket,
		"331 Please spcify the password.\r\n");
	}
}

void	pass(t_system *serv, char *argument)
{
	if (serv->username == NULL) {
		dprintf(serv->client.cmd_socket,
		"503 Login with USER first.\r\n");
		return;
	}
	if ((argument == NULL || strlen(argument) == 0)
	&& strcmp(serv->username, "Anonymous") == 0) {
		serv->logged = true;
		dprintf(serv->client.cmd_socket, "230 Login successful.\r\n");
	}
	else if (strcmp(serv->username, "Anonymous") != 0 || argument != NULL
	|| strlen(argument) == 0) {
		serv->username = NULL;
		dprintf(serv->client.cmd_socket, "530 Login incorrect.\r\n");
	}
}

void	quit(t_system *serv, char *argument)
{
	(void)argument;
	serv->running = false;
	serv->logged = false;
	serv->username = NULL;
	serv->password = NULL;
	dprintf(serv->client.cmd_socket, "221 Goodbye.\r\n");
	close(serv->client.cmd_socket);
}