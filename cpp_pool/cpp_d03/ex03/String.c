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
	this->append_c = str->append_c;
	this->append_s = str->append_s;
	this->at = str->at;
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
	this->append_c = &append_c;
	this->append_s = &append_s;
	this->at = &at;
}

void	StringDestroy(String *this)
{
	this->str = NULL;
	this->assign_s = NULL;
	this->assign_c = NULL;
	this->append_c = NULL;
	this->append_s = NULL;
	this->at = NULL;
}

void	append_s(String *this, const String *ap)
{
	this->str = strcat(strdup(this->str), strdup((char *)ap->str));
	this->assign_c = ap->assign_c;
	this->assign_s = ap->assign_s;
	this->append_c = ap->append_c;
	this->append_s = ap->append_s;
	this->at = ap->at;
}

void	append_c(String *this, const char *ap)
{
	this->str = strcat(strdup(this->str), strdup((char *)ap));
}

char	at(String *this, size_t pos)
{
	if (pos > strlen(this->str))
		return (-1);
	return(this->str[pos]);
}