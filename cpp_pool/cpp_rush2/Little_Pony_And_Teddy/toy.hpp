/*
** EPITECH PROJECT, 2018
** rush02
** File description:
** LittlePony and Teddy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include <iostream>
#include "object.hpp"

class	Toy : public Object
{
	public:
		Toy(const std::string &);
		~Toy();
};

#endif /* !TOY_HPP_ */
