/*
** EPITECH PROJECT, 2018
** string
** File description:
** string
*/

#include "String.h"
#include <stdio.h>

void	assign_s(String *this, const String *str)
{
	this->assign_c = str->assign_c;
	this->assign_s = str->assign_s;
	this->str = strdup((char *)str->str);
}

void	assign_c(String *this, const char *s)
{
	this->str = strdup((char *)s);
}

void	StringInit(String *this, const char *s)
{
	this->str = strdup((char *)s);
	this->assign_s = &assign_s;
	this->assign_c = &assign_c;
}

void	StringDestroy(String *this)
{
	this->str = NULL;
	this->assign_s = NULL;
	this->assign_c = NULL;
}