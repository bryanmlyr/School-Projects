/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** transfert
*/

#include "server.h"

void	stor(t_system *serv, char *arg)
{
	int	rd;
	char	c;

	if (transmissions_errors(serv, arg) == true)
		return;
	arg = strcat(strcat(strdup(serv->path), strdup("/")), strdup(arg));
	dprintf(serv->client.cmd_socket,
	"150 File status okay; about to open data connection.\r\n");
	int 	file_fd = open(arg, O_CREAT | O_TRUNC | O_RDWR, 0644);
	while ((rd = read(serv->client.data_socket, &c, 1)) > 0) {
		if (rd == 0 || rd == -1)
			break;
		write(file_fd, &c , 1);
	}
	close_transmissions(serv, file_fd, rd);
	serv->transmission = NONE;
}

void	retr(t_system *serv, char *arg)
{
	int	rd;
	char	c;

	if (transmissions_errors(serv, arg) == true)
		return;
	arg = strcat(strcat(strdup(serv->path), strdup("/")),strdup(arg));
	dprintf(serv->client.cmd_socket,
	"150 File status okay; about to open data connection.\r\n");
	int 	file_fd = open(arg, O_RDONLY);
	while ((rd = read(file_fd, &c, 1)) > 0) {
		if (rd == 0 || rd == -1)
			break;
		write(serv->client.data_socket, &c, 1);
	}
	close_transmissions(serv, file_fd, rd);
	serv->transmission = NONE;
}

void	dele(t_system *serv, char *arg)
{
	arg = strcat(strcat(strdup(serv->path), strdup("/")), strdup(arg));
	if (unlink(arg) == 0)
		dprintf(serv->client.cmd_socket,
		"250 Requested file action okay, completed.\r\n");
	else
		dprintf(serv->client.cmd_socket, "550 Permission denied.\r\n");
}

void	close_transmissions(t_system *serv, int file_fd, int rd)
{
	if (file_fd == -1 || rd == -1)
		dprintf(serv->client.cmd_socket, "552 File error.\r\n");
	else {
		dprintf(serv->client.cmd_socket, "226 Closing data sock.\r\n");
		close(file_fd);
	}
	close(serv->client.data_socket);
	close(serv->server.data_socket);
}