/*
** EPITECH PROJECT, 2018
** ex2
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut()
{
	_vitamins = 15;
	_fruitName = "coconut";
}

Coconut::~Coconut()
{
}

int Coconut::getVitamins() const
{
	return _vitamins;
}

std::string Coconut::getName() const
{
	return _fruitName;
}