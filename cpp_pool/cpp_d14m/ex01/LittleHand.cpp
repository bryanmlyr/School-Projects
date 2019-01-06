/*
** EPITECH PROJECT, 2018
** ex1
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

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