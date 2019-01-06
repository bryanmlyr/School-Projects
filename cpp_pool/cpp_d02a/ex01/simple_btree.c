/*
** EPITECH PROJECT, 2018
** btree
** File description:
** btree
*/

#include "simple_btree.h"
#include <stdlib.h>
#include <stdio.h>

bool_t btree_is_empty(tree_t tree)
{
	if (tree == NULL)
		return (TRUE);
	return (FALSE);
}

unsigned int btree_get_size(tree_t tree)
{
	if (tree != NULL) {
		return (btree_get_size(tree->left)
		+ btree_get_size(tree->right) + 1);
	} else {
		return (0);
	}
}

unsigned int btree_get_depth(tree_t tree)
{
	if (tree != NULL) {
		unsigned int left_d = btree_get_depth(tree->left);
		unsigned int right_d = btree_get_depth(tree->right);

		if (left_d > right_d) {
			return (left_d + 1);
		} else {
			return (right_d + 1);
		}
	} else {
		return (0);
	}
}

bool_t	btree_create_node(tree_t *node_ptr, double value)
{
	tree_t new_elem = malloc(sizeof(tree_t));

	if (new_elem == NULL)
		return (FALSE);
	new_elem->value = value;
	new_elem->left = NULL;
	new_elem->right = NULL;
	*node_ptr = new_elem;
	return (TRUE);
}

bool_t	btree_delete(tree_t *root_ptr)
{
	if (*root_ptr == NULL)
		return (FALSE);
	(*root_ptr)->left = NULL;
	(*root_ptr)->right = NULL;
	return (TRUE);
}

double	btree_get_max_value(tree_t tree)
{
	if (tree == NULL) {
		return (0);
	} else {
		double db = tree->value;
		double db_left = btree_get_max_value(tree->left);
		double db_right = btree_get_max_value(tree->right);

		if (db_left > db)
			db = db_left;
		if (db_right > db)
			db = db_right;
		return (db);
	}
}

double	btree_get_min_value(tree_t tree)
{
	if (tree == NULL) {
		return (0);
	} else {
		double db = tree->value;
		double db_left = btree_get_min_value(tree->left);
		double db_right = btree_get_min_value(tree->right);

		if (db_left < db)
			db = db_left;
		if (db_right < db)
			db = db_right;
		return (db);
	}
}