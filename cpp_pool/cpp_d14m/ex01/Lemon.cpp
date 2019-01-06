/*
** EPITECH PROJECT, 2018
** ex0
** File description:
** lemon
*/

#include "Lemon.hpp"

Lemon::Lemon()
{
	_vitamins = 3;
	_fruitName = "lemon";
}

Lemon::~Lemon()
{
}

int	Lemon::getVitamins() const
{
	return _vitamins;
}

std::string	Lemon::getName() const
{
	return _fruitName;
}