/*
** EPITECH PROJECT, 2018
** ex0
** File description:
** Banana
*/

#include "Banana.hpp"

Banana::Banana()
{
	_vitamins = 5;
	_fruitName = "banana";
}

Banana::~Banana()
{
}

int	Banana::getVitamins() const
{
	return _vitamins;
}

std::string	Banana::getName() const
{
	return _fruitName;
}
