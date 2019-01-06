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
	this->str = strdup((char *)str->str);
	this->assign_c = str->assign_c;
	this->assign_s = str->assign_s;
	this->append_c = str->append_c;
	this->append_s = str->append_s;
	this->at = str->at;
	this->clear = str->clear;
	this->size = str->size;
	this->compare_c = str->compare_c;
	this->compare_s = str->compare_s;
	this->copy = str->copy;
	this->c_str = str->c_str;
	this->empty = str->empty;
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
	this->clear = &clear;
	this->size = &size;
	this->compare_c = &compare_c;
	this->compare_s = &compare_s;
	this->copy = &copy;
	this->c_str = &c_str;
	this->empty = &empty;
}

void	StringDestroy(String *this)
{
	this->str = NULL;
	this->assign_s = NULL;
	this->assign_c = NULL;
	this->append_c = NULL;
	this->append_s = NULL;
	this->at = NULL;
	this->clear = NULL;
	this->size = NULL;
	this->compare_c = NULL;
	this->compare_s = NULL;
	this->copy = NULL;
	this->c_str = NULL;
	this->empty = NULL;
}

void	append_s(String *this, const String *ap)
{
	this->str = strcat(strdup(this->str), strdup((char *)ap->str));
	this->assign_c = ap->assign_c;
	this->assign_s = ap->assign_s;
	this->append_c = ap->append_c;
	this->append_s = ap->append_s;
	this->at = ap->at;
	this->clear = ap->clear;
	this->size = ap->size;
	this->compare_c = ap->compare_c;
	this->compare_s = ap->compare_s;
	this->copy = ap->copy;
	this->c_str = ap->c_str;
	this->empty = ap->empty;
}

void	append_c(String *this, const char *ap)
{
	this->str = strcat(strdup(this->str), strdup((char *)ap));
}

char	at(String *this, size_t pos)
{
	if (pos > strlen(this->str))
		return (-1);
	return (this->str[pos]);
}

void	clear(String *str)
{
	if (str->str != NULL)
		str->str = calloc(strlen(str->str), sizeof(char));
}

int	size(String *str)
{
	if (str->str != NULL)
		return (strlen(str->str));
	return (-1);
}

int	compare_s(String *this, const String *str)
{
	return (strcmp(this->str, str->str));
}

int	compare_c(String *this, const char *str)
{
	return (strcmp(this->str, str));
}

size_t	copy(String *this, char *s, size_t n, size_t pos)
{
	size_t x = 0;

	while (x < n && this->str[pos] != 0) {
		s[x] = this->str[pos];
		x++;
		pos++;
	}
	return (x);
}

const char	*c_str(String *this)
{
	if (this->str != NULL)
		return ((const char *)this->str);
	else
		return (NULL);
}

int	empty(String *this)
{
	if (this->str == NULL || strlen(this->str) == 0)
		return (1);
	else
		return (-1);
}