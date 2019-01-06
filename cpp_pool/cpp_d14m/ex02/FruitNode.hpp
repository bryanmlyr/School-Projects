/*
** EPITECH PROJECT, 2018
** ex0
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
	#define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct List
{
	Fruit		*data;
	struct List 	*next;
}			FruitNode;

int 		ListLen(FruitNode *);
FruitNode	*pushBack(FruitNode *, Fruit *);
FruitNode	*removeHead(FruitNode *);

#endif /* !FRUITNODE_HPP_ */
