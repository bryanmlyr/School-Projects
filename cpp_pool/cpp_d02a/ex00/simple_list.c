/*
** EPITECH PROJECT, 2018
** CPP Pool
** File description:
** ex00 d02a
*/

#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int	list_get_size(list_t list)
{
	unsigned int ret = 0;

	while (list) {
		list = list->next;
		ret++;
	}
	return (ret);
}

bool_t	list_is_empty(list_t list)
{
	if (list == NULL)
		return (TRUE);
	return (FALSE);
}

void	list_dump(list_t list)
{
	while (list) {
		printf("%f\n", list->value);
		list = list->next;
	}
}

bool_t	list_add_elem_at_front(list_t *front_ptr, double elem)
{
	list_t	newelem = malloc(sizeof(list_t));

	if (newelem == NULL)
		return (FALSE);
	newelem->value = elem;
	newelem->next = *front_ptr;
	*front_ptr = newelem;
	return (TRUE);
}

bool_t	list_add_elem_at_back(list_t *front_ptr , double elem)
{
	list_t	first_save = *front_ptr;
	list_t	new_elem = malloc(sizeof(list_t));

	if (new_elem == NULL)
		return (FALSE);
	new_elem->value = elem;
	new_elem->next = NULL;
	if (list_is_empty(*front_ptr) == TRUE) {
		(*front_ptr) = new_elem;
	} else {
		while ((*front_ptr)->next != NULL) {
			(*front_ptr) = (*front_ptr)->next;
		}
		(*front_ptr)->next = new_elem;
		*front_ptr = first_save;
	}
	return (TRUE);
}

bool_t	list_add_elem_at_position(list_t *front_ptr,
					double elem, unsigned int position)
{
	unsigned int	cur_pos = 0, len = list_get_size(*front_ptr);
	list_t		new_list = NULL;

	if (position == 0)
		return (list_add_elem_at_front(front_ptr, elem));
	if (position > len)
		return (FALSE);
	if (position == len)
		return (list_add_elem_at_back(front_ptr, elem));
	while (*front_ptr) {
		if (cur_pos != position) {
			list_add_elem_at_back(&new_list, (*front_ptr)->value);
			(*front_ptr) = (*front_ptr)->next;
		} else {
			list_add_elem_at_back(&new_list, elem);
		}
		cur_pos++;
	}
	*front_ptr = new_list;
	return (TRUE);
}

bool_t	list_del_elem_at_front(list_t *front_ptr)
{
	list_t	free_tmp = *front_ptr;

	if (*front_ptr == NULL)
		return (FALSE);
	(*front_ptr) = (*front_ptr)->next;
	free(free_tmp);
	return (TRUE);
}

bool_t	list_del_elem_at_back(list_t *front_ptr)
{
	list_t	root = *front_ptr;

	if (*front_ptr == NULL)
		return (FALSE);
	if (list_get_size(*front_ptr) == 1) {
		*front_ptr = NULL;
		return (TRUE);
	}
	if (list_get_size(*front_ptr) == 2) {
		(*front_ptr)->next = NULL;
		return (TRUE);
	}
	while ((*front_ptr)->next->next != NULL) {
		(*front_ptr) = (*front_ptr)->next;
	}
	(*front_ptr)->next = NULL;
	(*front_ptr) = root;
	return (TRUE);
}

bool_t	list_del_elem_at_position(list_t *front_ptr,
					unsigned int position)
{
	unsigned int	cur_pos = 0;
	list_t		new_list = NULL;

	while (*front_ptr) {
		if (cur_pos != position) {
			list_add_elem_at_back(&new_list, (*front_ptr)->value);
			(*front_ptr) = (*front_ptr)->next;
		} else {
			(*front_ptr) = (*front_ptr)->next;
		}
		cur_pos++;
	}
	*front_ptr = new_list;
	return (TRUE);
}

double	list_get_elem_at_front(list_t list)
{
	if (list == NULL)
		return (0);
	return (list->value);
}

double	list_get_elem_at_back(list_t list)
{
	if (list == NULL)
		return (0);
	while (list->next) {
		list = list->next;
	}
	return (list->value);
}

double	list_get_elem_at_position(list_t list, unsigned int position)
{
	unsigned int x = 0;

	while (x != position && list) {
		list = list->next;
		x++;
	}
	return (list->value);
}

node_t	*list_get_first_node_with_value(list_t list, double value)
{
	while (list) {
		if (list->value == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}