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
#include <string.h>

typedef	struct 	String
{
	char	*str;
	void	(*assign_s)(struct String *, const struct String *);
	void	(*assign_c)(struct String *, const char *);
}		String;

void	assign_s(String *, const String *);
void	assign_c(String *, const char *);
void	StringDestroy(String *);
void	StringInit(String *, const char *);

#endif /* !STRING_H_ */
