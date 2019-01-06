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
}		String;

void	StringDestroy(String *);
void	StringInit(String *, const char *);

#endif /* !STRING_H_ */
