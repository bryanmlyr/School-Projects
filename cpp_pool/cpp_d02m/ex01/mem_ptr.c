/*
** EPITECH PROJECT, 2018
** CPP pool
** File description:
** mem ptr ex01
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mem_ptr.h"

void	add_str(char *str1 , char *str2 , char **res)
{
	*res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
	if (*res != NULL)
		*res = strcat(strdup(str1), strdup(str2));
}

void	add_str_struct(str_op_t *str_op)
{
	str_op->res = malloc(sizeof(char) * (strlen(str_op->str1)
	+ strlen(str_op->str2) + 1));
	if (str_op->res != NULL)
		str_op->res = strcat(strdup(str_op->str1)
		, strdup(str_op->str2));
}