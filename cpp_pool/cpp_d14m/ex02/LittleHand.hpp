/*
** EPITECH PROJECT, 2018
** ex1
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
	#define LITTLEHAND_HPP_

#include "FruitBox.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "Banana.hpp"
#include "Coconut.hpp"

class LittleHand {
	public:
		LittleHand();
		~LittleHand();
		static void sortFruitBox(FruitBox &, FruitBox &, FruitBox &, FruitBox &);
		static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
};

#endif /* !LITTLEHAND_HPP_ */
