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
	const char *	(*c_str)(struct String *);
	int	(*empty)(struct String *);
	int	(*find_c)(struct String *, const char *, size_t);
	int	(*find_s)(struct String *, const struct String *, size_t);
	void	(*insert_c)(struct String *, size_t, const char *);
	void	(*insert_s)(struct String *, size_t, const struct String *);
	int	(*to_int)(struct String *);
	struct String *	(*split_s)(struct String *, char);
	char **	(*split_c)(struct String *, char);
	void	(*aff)(struct String *);
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
int	empty(String *);
const char *c_str(String *);
int 	find_s(String *, const String *, size_t);
int 	find_c(String *, const char *, size_t);
void	insert_c(String *, size_t, const char *);
void	insert_s(String *, size_t, const String *);
int	to_int(String *);
String	*split_s(String *, char);
char	**split_c(String *, char);
void	aff(String *);

#endif /* !STRING_H_ */