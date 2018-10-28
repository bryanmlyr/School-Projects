/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** server
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <stdbool.h>
#include <ctype.h>

enum CMD {
	USER,
	PASS,
	CWD,
	CDUP,
	QUIT,
	PORT,
	PASV,
	STOR,
	RETR,
	LIST,
	DELE,
	PWD,
	HELP,
	NOOP
};

enum	TRANSMISSION
{
	NONE,
	PASSIVE,
	ACTIVE
};

struct	system;

typedef	struct	cmd
{
	enum CMD	cmd;
	char		*cmd_pattern;
	void		(*cmd_function)(struct system *, char *);
}	t_cmd;

typedef	struct	entity
{
	int	data_socket;
	int	cmd_socket;
	short	data_port;
	short	cmd_port;
}	t_entity;

typedef	struct	system
{
	bool			logged;
	bool			running;
	char			*username;
	char			*password;
	char			*root;
	char			*path;
	t_cmd			*cmds;
	t_entity		server;
	t_entity		client;
	enum TRANSMISSION	transmission;
}	t_system;

void		user(t_system *, char *);
void		pass(t_system *, char *);
void		cwd(t_system *, char *);
void		cdup(t_system *, char *);
void		quit(t_system *, char *);
void		port(t_system *, char *);
void		pasv(t_system *, char *);
void		stor(t_system *, char *);
void		retr(t_system *, char *);
void		list(t_system *, char *);
void		dele(t_system *, char *);
void		pwd(t_system *, char *);
void		help(t_system *, char *);
void		noop(t_system *, char *);
void		active(t_system *);
void		passive(t_system *);
void		passive(t_system *);
void		bind_socket(int, int);
void		do_command(char *, t_system *);
void		close_transmissions(t_system *, int, int);
char		*epur_str(char *);
char		*get_arg(char *);
char		*catch_command(t_system *);
int		create_socket(void);
int		is_directory(char *);
bool		create_client(t_system *);
bool		transmissions_errors(t_system *, char *);
t_system	init_server(int, char *);
