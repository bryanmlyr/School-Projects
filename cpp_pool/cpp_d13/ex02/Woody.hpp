/*
** EPITECH PROJECT, 2018
** Exercise 2
** File description:
** Woody
*/

#ifndef WOODY_HPP_
	#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
	public:
		Woody(const std::string &);
		Woody(const std::string &, const std::string &);
		~Woody();
};

#endif /* !WOODY_HPP_ */
