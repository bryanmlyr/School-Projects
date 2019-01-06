/*
** EPITECH PROJECT, 2018
** string
** File description:
** string
*/

#ifndef STRING_H_
	#define STRING_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef	struct 	String
{
	char	*str;
	void	(*assign_s)(struct String *, const struct String *);
	void	(*assign_c)(struct String *, const char *);
	void	(*append_s)(struct String *, const struct String *);
	void	(*append_c)(struct String *, const char *);
	char	(*at)(struct String *, size_t);
	void	(*clear)(struct String *);
	int	(*size)(struct String *);
	int	(*compare_c)(struct String *, const char *);
	int	(*compare_s)(struct String *, const struct String *);
	size_t	(*copy)(struct String *, char *, size_t, size_t);
}		String;

void	append_s(String *, const String *);
void	append_c(String *, const char *);
void	assign_s(String *, const String *);
void	assign_c(String *, const char *);
void	StringDestroy(String *);
void	StringInit(String *, const char *);
char	at(String *, size_t);
void	clear(String *);
int	size(String *);
int	compare_s(String *, const String *);
int	compare_c(String *, const char *);
size_t	copy(String *, char *, size_t, size_t);

#endif /* !STRING_H_ */