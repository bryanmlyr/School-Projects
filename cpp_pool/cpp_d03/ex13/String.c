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
	this->find_c = str->find_c;
	this->find_s = str->find_s;
	this->insert_c = str->insert_c;
	this->insert_s = str->insert_s;
	this->to_int = str->to_int;
	this->split_s = str->split_s;
	this->split_c = str->split_c;
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
	this->find_c = &find_c;
	this->find_s = &find_s;
	this->insert_c = &insert_c;
	this->insert_s = &insert_s;
	this->to_int = &to_int;
	this->split_s = &split_s;
	this->split_c = &split_c;
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
	this->find_c = NULL;
	this->find_s = NULL;
	this->insert_c = NULL;
	this->insert_s = NULL;
	this->to_int = NULL;
	this->split_s = NULL;
	this->split_c = NULL;
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
	this->find_s = ap->find_s;
	this->find_c = ap->find_c;
	this->insert_c = ap->insert_c;
	this->insert_s = ap->insert_s;
	this->to_int = ap->to_int;
	this->split_s = ap->split_s;
	this->split_c = ap->split_c;
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

int 	find_s(String *this, const String *str, size_t pos)
{
	char *s = NULL;

	if ((strlen(str->str) + pos) > strlen(this->str) || str->str == NULL)
		return (-1);
	this->str += pos;
	s = strstr(this->str, str->str);
	if (s == NULL)
		return (-1);
	this->str -= pos;
	return (s - this->str);
}

int 	find_c(String *this, const char *str, size_t pos)
{
	char *s = NULL;

	if ((strlen(str) + pos) > strlen(this->str) || str == NULL)
		return (-1);
	this->str += pos;
	s = strstr(this->str, str);
	if (s == NULL)
		return (-1);
	this->str -= pos;
	return (s - this->str);
}

void	insert_c(String *this, size_t pos, const char *str)
{
	char	*tmp = malloc(sizeof(char) * (strlen(this->str) +
			strlen(str) + 1));
	unsigned int	x = 0, a = 0, z = 0;

	while (x < pos && this->str[x]) {
		tmp[x] = this->str[x];
		x++;
	}
	a = x;
	while (str[z])
		tmp[a++] = str[z++];
	while (x < strlen(this->str) && this->str[x])
		tmp[a++] = this->str[x++];
	tmp[a] = '\0';
	this->str = tmp;
}

void	insert_s(String *this, size_t pos, const String *str)
{
	char	*tmp = malloc(sizeof(char) * (strlen(this->str) +
			strlen(str->str) + 1));
	unsigned int	x = 0, a = 0, z = 0;

	while (x < pos && this->str[x]) {
		tmp[x] = this->str[x];
		x++;
	}
	a = x;
	while (str->str[z])
		tmp[a++] = str->str[z++];
	while (x < strlen(this->str) && this->str[x])
		tmp[a++] = this->str[x++];
	tmp[a] = '\0';
	this->str = tmp;
}

int	to_int(String *this)
{
	return (atoi(this->str));
}

String	*split_s(String *this, char separator)
{
	String	*output = malloc(sizeof(String) * (strlen(this->str) + 1));
	char	*temp;
	int	x = 0, y = 0, a = 0;

	while (this->str[x]) {
		temp = malloc(sizeof(char) * (strlen(this->str) + 1));
		a = 0;
		while (this->str[x] != separator && this->str[x])
			temp[a++] = this->str[x++];
		StringInit(&output[y++], temp);
		if (this->str[x])
			x++;
	}
	return (output);
}

char	**split_c(String *this, char separator)
{
	char	**output = malloc(sizeof(char *) * (strlen(this->str) + 1));
	char	*temp;
	int	x = 0, y = 0, a = 0;

	while (this->str[x]) {
		temp = malloc(sizeof(char) * (strlen(this->str) + 1));
		a = 0;
		while (this->str[x] != separator && this->str[x])
			temp[a++] = this->str[x++];
		output[y++] = temp;
		if (this->str[x])
			x++;
	}
	return (output);
}