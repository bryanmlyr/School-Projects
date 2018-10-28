/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** list
*/

#include "server.h"

void	list_handling(t_system *serv, char *arg)
{
	dprintf(serv->client.cmd_socket, "150 Here comes the directory.\r\n");
	int origin_fd = dup(1);
	dup2(serv->client.data_socket, 1);
	if (system(strcat(strdup("ls -l "), arg)) == 0)
		dprintf(serv->client.cmd_socket, "226 Directory send OK.\r\n");
	else
		dprintf(serv->client.cmd_socket, "552 An error occurred.\r\n");
	dup2(origin_fd, 1);
	close(serv->client.data_socket);
	close(serv->server.data_socket);
	serv->transmission = NONE;
}

void	list(t_system *serv, char *arg)
{
	if (serv->client.data_socket == -1 || serv->transmission == NONE) {
		dprintf(serv->client.cmd_socket, "425 Use PORT or PASV.\r\n");
		return;
	}
	if (arg != NULL && strlen(arg) > 0)
		arg = strcat(strcat(strdup(serv->path), strdup("/")),
		strdup(arg));
	else
		arg = strdup(serv->path);
	list_handling(serv, arg);
}