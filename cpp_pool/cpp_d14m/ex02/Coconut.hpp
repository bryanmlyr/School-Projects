/*
** EPITECH PROJECT, 2018
** ex2
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
	#define COCONUT_HPP_

#include "Fruit.hpp"

class Coconut : public Fruit {
	public:
		Coconut();
		~Coconut();
		int getVitamins() const;
		std::string getName() const;
};

#endif /* !COCONUT_HPP_ */
