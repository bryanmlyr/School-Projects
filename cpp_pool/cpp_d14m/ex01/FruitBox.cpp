/*
** EPITECH PROJECT, 2018
** ex0
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

int 	ListLen(FruitNode *list)
{
	int x = 0;

	while (list) {
		list = list->next;
		x++;
	}
	return x;
}

FruitNode	*pushBack(FruitNode *list, Fruit *data)
{
	FruitNode	*newElem = new FruitNode;
	FruitNode	*head = list;

	newElem->data = data;
	newElem->next = NULL;
	if (ListLen(list) == 0) {
		list = newElem;
	} else {
		while (list->next) {
			list = list->next;
		}
		list->next = newElem;
		list = head;
	}

	return list;
}

FruitNode	*removeHead(FruitNode *list)
{
	if (ListLen(list) == 0) {
		return NULL;
	} else {
		list = list->next;
		return list;
	}
}

FruitBox::FruitBox(int size)
{
	_boxSize = size;
}

FruitBox::~FruitBox()
{
}

int	FruitBox::nbFruits() const
{
	return ListLen(_list);
}

bool	checkExist(Fruit *elem, List *list)
{
	while (list)
	{
		if (elem == list->data)
			return true;
		list = list->next;
	}
	return false;
}

bool	FruitBox::putFruit(Fruit *elem)
{
	if (elem == NULL)
		return false;
	if (ListLen(_list) < _boxSize) {
		if (checkExist(elem, _list) == true)
			return false;
		_list = pushBack(_list, elem);
		return true;
	} else {
		return false;
	}
}

Fruit	*FruitBox::pickFruit()
{
	Fruit	*tmp;

	if (_list) {
		if (_list->data) {
			tmp = _list->data;
			_list = removeHead(_list);
			return tmp;
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}

FruitNode	*FruitBox::head() const
{
	return _list;
}