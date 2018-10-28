/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** main
*/

#include "server.h"

bool	errors(int ac, char **av)
{
	if (ac != 3) {
		dprintf(2, "./server [PORT] [PATH]\n");
		return (true);
	}
	for (int x = 0; av[1][x]; x++)
		if (!isdigit(av[1][x])) {
			dprintf(2, "Argument 1 need to be a port number\n");
			return (true);
		}
	if (is_directory(av[2]) == false) {
		dprintf(2, "Failed to open directory %s\n", av[2]);
		return (true);
	}
	return (false);
}

void	signal_handler(int sig)
{
	if (sig == SIGINT) {
		printf("Good bye !!!\n");
		exit(0);
	}
}

void	run_server(t_system server, pid_t pid)
{
	if (pid != 0) {
		dprintf(server.client.cmd_socket,
		"220 Service ready for new user.\r\n");
		server.running = true;
		while (server.running != false) {
			do_command(catch_command(&server), &server);
			usleep(50000);
		}
		kill(pid, SIGINT);
	}
}

int			main(int ac, char **av)
{
	if (errors(ac, av) == true)
		return (84);
	t_system	server = init_server(atoi(av[1]), av[2]);

	signal(SIGINT, signal_handler);
	if (listen(server.server.cmd_socket, 5) == -1) {
		dprintf(2, "Failed to listen server CMD socket\n");
		return (84);
	}
	while (1)
		if (create_client(&server) == true) {
			pid_t pid = fork();
			run_server(server, pid);
		}
	return (0);
}