/*
** EPITECH PROJECT, 2018
** ex0
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
	#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
	public:
		FruitBox(int);
		~FruitBox();
		int		nbFruits() const;
		bool		putFruit(Fruit *);
		Fruit		*pickFruit();
		FruitNode 	*head() const;
	private:
		int		_boxSize;
		FruitNode	*_list = NULL;
};

int 		ListLen(FruitNode *);
FruitNode	*pushBack(FruitNode *, Fruit *);
FruitNode	*removeHead(FruitNode *);

#endif /* !FRUITBOX_HPP_ */
