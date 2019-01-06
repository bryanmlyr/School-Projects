/*
** EPITECH PROJECT, 2018
** ex1
** File description:
** LittleHand
*/

#include "LittleHand.hpp"
#include <iostream>

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void	LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
	FruitNode *unsortedList = unsorted.head();

	while (unsortedList) {
		if (dynamic_cast<Lime *>(unsortedList->data))
			limes.putFruit(unsortedList->data);
		else if (dynamic_cast<Lemon *>(unsortedList->data))
			lemons.putFruit(unsortedList->data);
		else if (dynamic_cast<Banana *>(unsortedList->data))
			bananas.putFruit(unsortedList->data);
		unsortedList = unsortedList->next;
	}
}

FruitBox * const * LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
	int		size = 0, alloc = 1, a = 0;
	FruitBox	**ret;

	while (coconuts && coconuts[size])
		size++;
	if (size > 0)
		alloc = size / 6 + size % 6 + 1;
	ret = new FruitBox *[alloc];
	ret[0] = new FruitBox;
	for (int x = 0; x <= size && coconuts && coconuts[x]; x++) {
		ret[a]->putFruit(const_cast<Coconut *>(coconuts[x]));
		if (x % 6 == 0)
			ret[++a] = new FruitBox;
	}
	return ret;
}
