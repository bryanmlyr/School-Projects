/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** moves
*/

#include "server.h"

void	cwd(t_system *serv, char *argument)
{
	if (argument == NULL || strlen(argument) == 0)
		dprintf(serv->client.cmd_socket,
		"550 Failed to change directory.\r\n");
	else if (is_directory(strcat(strcat(strdup(serv->path), strdup("/")),
	strdup(argument))) != 0) {
		serv->path = strcat(strcat(serv->path, strdup("/")),
		strdup(argument));
		dprintf(serv->client.cmd_socket,
		"250 Requested file action okay, completed.\r\n");
		return;
	} else {
		dprintf(serv->client.cmd_socket,
		"550 Failed to change directory.\r\n");
	}
}

void	cdup(t_system *serv, char *argument)
{
	(void)argument;
	serv->path = strdup(serv->root);
	dprintf(serv->client.cmd_socket,
	"250 Directory successfully changed.\r\n");
}

void	pwd(t_system *serv, char *argument)
{
	(void)argument;
	char	*buffer = getcwd(NULL, BUFSIZ);

	if (buffer != NULL)
		dprintf(serv->client.cmd_socket, "257 \"%s\"\r\n",
		strcat(strcat(buffer, strdup("/")), serv->path));
}

void	help(t_system *serv, char *argument)
{
	(void)argument;

	dprintf(serv->client.cmd_socket, "214 Help OK.\r\n");
}

void	noop(t_system *serv, char *argument)
{
	(void)argument;

	dprintf(serv->client.cmd_socket, "200 NOOP ok.\r\n");
}