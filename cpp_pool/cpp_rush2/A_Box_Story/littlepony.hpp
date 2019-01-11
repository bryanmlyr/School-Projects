/*
** EPITECH PROJECT, 2018
** rush02
** File description:
** LittlePony and Teddy
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include <string>
#include <iostream>
#include "toy.hpp"

class	LittlePony : public Toy
{
	public:
		LittlePony(const std::string &);
		~LittlePony();
		void isTaken();
};

#endif /* !LITTLEPONY_HPP_ */
