/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** init
*/

#include "server.h"

int		create_socket(void)
{
	int	socket_fd = socket(AF_INET, SOCK_STREAM, 6);
	int	param = 1;

	if (socket_fd == -1)
		dprintf(2, "Failed to create a new socket\n");
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &param, sizeof(param));
	return (socket_fd);
}

t_cmd		*build_cmd(void)
{
	t_cmd	*cmds = malloc(sizeof(t_cmd) * 14);

	cmds[USER] = (t_cmd){USER, "USER", &user};
	cmds[PASS] = (t_cmd){PASS, "PASS", &pass};
	cmds[CWD] = (t_cmd){CWD, "CWD", &cwd};
	cmds[CDUP] = (t_cmd){CDUP, "CDUP", &cdup};
	cmds[QUIT] = (t_cmd){QUIT, "QUIT", &quit};
	cmds[PORT] = (t_cmd){PORT, "PORT", &port};
	cmds[PASV] = (t_cmd){PASV, "PASV", &pasv};
	cmds[STOR] = (t_cmd){STOR, "STOR", &stor};
	cmds[RETR] = (t_cmd){RETR, "RETR", &retr};
	cmds[LIST] = (t_cmd){LIST, "LIST", &list};
	cmds[DELE] = (t_cmd){DELE, "DELE", &dele};
	cmds[PWD] = (t_cmd){PWD, "PWD", &pwd};
	cmds[HELP] = (t_cmd){HELP, "HELP", &help};
	cmds[NOOP] = (t_cmd){NOOP, "NOOP", &noop};

	return (cmds);
}

void				bind_socket(int socket_fd, int port)
{
	struct sockaddr_in	sock;

	sock.sin_family = AF_INET;
	sock.sin_port = htons(port);
	sock.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(socket_fd, (struct sockaddr *)&sock, sizeof(sock)) == -1) {
		dprintf(2, "Failed to bind a socket %d\n", socket_fd);
		exit(84);
	}
}

t_system		init_server(int cmd_port, char *path)
{
	t_system	ret;

	ret.logged = false;
	ret.running = false;
	ret.username = NULL;
	ret.password = NULL;
	ret.root = strdup(path);
	ret.path = strdup(path);
	ret.cmds = build_cmd();
	ret.server.data_port = -1;
	ret.server.data_socket = -1;
	ret.server.cmd_port = cmd_port;
	ret.server.cmd_socket = create_socket();
	ret.client.data_port = -1;
	ret.client.data_socket = -1;
	ret.client.cmd_port = -1;
	ret.client.cmd_socket = -1;
	ret.transmission = NONE;
	bind_socket(ret.server.cmd_socket, cmd_port);
	return (ret);
}

bool	transmissions_errors(t_system *serv, char *arg)
{
	if (serv->client.data_socket == -1 || serv->transmission == NONE) {
		dprintf(serv->client.cmd_socket, "425 Use PORT or PASV.\r\n");
		return (true);
	}
	if (arg == NULL || strlen(arg) == 0) {
		dprintf(serv->client.cmd_socket, "530 Permission denied.\r\n");
		return (true);
	}
	return (false);
}