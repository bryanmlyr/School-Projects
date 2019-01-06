/*
** EPITECH PROJECT, 2018
** ex0
** File description:
** lemon
*/

#ifndef LEMON_HPP_
	#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : public Fruit {
	public:
		Lemon();
		~Lemon();
		int getVitamins() const;
		std::string getName() const;
};

#endif /* !LEMON_HPP_ */
