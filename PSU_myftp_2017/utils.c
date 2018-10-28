/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** utils
*/

#include "server.h"

char	*catch_command(t_system *server)
{
	if (server->client.cmd_socket != -1) {
		char *cmd = malloc(sizeof(char) * (BUFSIZ + 1));
		bzero(cmd, BUFSIZ + 1);
		read(server->client.cmd_socket, cmd, BUFSIZ);
		return (cmd);
	}
	return (NULL);
}

char	*get_arg(char *cmd)
{
	unsigned int x = 0;
	unsigned int a = 0;

	for (x = 0; cmd[x] != ' ' && cmd[x]; x++)
		if (cmd[x] == ' ')
			a = 1;
	if (cmd[x] == 0 && a == 1)
		return (NULL);
	if (cmd[x] == 0 && a != 1)
		return (cmd);
	char *ret = cmd + x;
	return (ret);
}

int	is_directory(char *path)
{
	struct stat st;

	if (stat(path, &st) != 0)
		return (0);
	return (S_ISDIR(st.st_mode));
}

char	*epur_str(char *str)
{
	if (str == NULL)
		return (NULL);
	char		*ret = malloc(sizeof(char) * (strlen(str) + 1));
	unsigned int	x = 0;
	unsigned int	a = 0;

	bzero(ret, strlen(str) + 1);
	while (str[x]) {
		if (str[x] != '\0' && str[x] != '\n' && str[x] != '\r')
			ret[a++] = str[x];
		x++;
	}
	ret[a] = 0;
	return (ret);
}

bool	create_client(t_system *server)
{
	struct sockaddr_in client_in;
	unsigned int len = sizeof(client_in);
	int new_fd = accept(server->server.cmd_socket,
	(struct sockaddr *)&client_in, &len);

	if (new_fd == -1) {
		dprintf(2, "Failed to accept new client\n");
		return (false);
	} else {
		server->client.cmd_port = (int)ntohs(client_in.sin_addr.s_addr);
		server->client.cmd_socket = new_fd;
		return (true);
	}

}