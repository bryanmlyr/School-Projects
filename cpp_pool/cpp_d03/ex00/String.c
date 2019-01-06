/*
** EPITECH PROJECT, 2018
** string
** File description:
** string
*/

#include "String.h"

void	StringInit(String *this, const char *s)
{
	this->str = strdup((char *)s);
}

void	StringDestroy(String *this)
{
	this->str = NULL;
}