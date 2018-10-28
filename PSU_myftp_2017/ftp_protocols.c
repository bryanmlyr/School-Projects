/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** ftp_protocols
*/

#include "server.h"

void	port(t_system *serv, char *argument)
{
	if (serv->transmission != NONE) {
		close(serv->server.data_socket);
		close(serv->client.data_socket);
	}
	serv->server.data_port = atoi(argument);
	serv->transmission = ACTIVE;
	active(serv);
	dprintf(serv->client.cmd_socket,
	"200 Command okay.\r\n");
}

void	active(t_system *server)
{
	struct sockaddr_in client;
	if (server->transmission == ACTIVE) {
		server->client.data_socket = create_socket();
		client.sin_family = AF_INET;
		client.sin_port = htons(server->server.data_port);
		client.sin_addr.s_addr = inet_addr("127.0.0.1");
		connect(server->client.data_socket, (struct sockaddr *)&client,
		sizeof(client));
	}
}

void	pasv(t_system *serv, char *argument)
{
	(void)argument;
	struct sockaddr_in client;
	unsigned int len = sizeof(client);

	if (serv->transmission != NONE) {
		close(serv->server.data_socket);
		close(serv->client.data_socket);
	}
	serv->transmission = PASSIVE;
	serv->server.data_port = 1024;
	passive(serv);
	dprintf(serv->client.cmd_socket,
	"227 Entering Passive Mode (127,0,0,1,%d,%d).\r\n",
	serv->server.data_port / 256, serv->server.data_port % 256);
	client.sin_family = AF_INET;
	client.sin_port = htons(serv->server.data_port);
	client.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv->client.data_socket = accept(serv->server.data_socket,
	(struct sockaddr *)&client, &len);
}

void	passive(t_system *server)
{
	struct sockaddr_in client;
	unsigned int len = sizeof(client);

	if (server->transmission == PASSIVE) {
		server->server.data_socket = create_socket();
		bind_socket(server->server.data_socket,
		server->server.data_port);
		client.sin_family = AF_INET;
		client.sin_port = 0;
		client.sin_addr.s_addr = inet_addr("127.0.0.1");
		listen(server->server.data_socket, 5);
		getsockname(server->server.data_socket,
		(struct sockaddr *)&client, &len);
		server->server.data_port = ntohs(client.sin_port);
	}
}