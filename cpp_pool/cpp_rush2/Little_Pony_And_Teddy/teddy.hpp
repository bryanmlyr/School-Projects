/*
** EPITECH PROJECT, 2018
** rush02
** File description:
** LittlePony and Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include <string>
#include <iostream>
#include "toy.hpp"

class	Teddy : public Toy
{
	public:
		Teddy(const std::string &);
		~Teddy();
		void isTaken();
};

#endif /* !TEDDY_HPP_ */
