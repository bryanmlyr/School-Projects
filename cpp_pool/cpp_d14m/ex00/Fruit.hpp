/*
** EPITECH PROJECT, 2018
** Exercise 0
** File description:
** Fruits
*/

#ifndef FRUIT_HPP_
	#define FRUIT_HPP_

#include <string>

class Fruit {
	public:
		Fruit();
		virtual ~Fruit();
		virtual int getVitamins() const = 0;
		virtual std::string getName() const = 0;
	protected:
		int		_vitamins;
		std::string	_fruitName;
};

#endif /* !FRUIT_HPP_ */
