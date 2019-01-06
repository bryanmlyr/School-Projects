/*
** EPITECH PROJECT, 2018
** pool
** File description:
** rad scorpion
*/

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}