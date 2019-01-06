/*
** EPITECH PROJECT, 2018
** pool
** File description:
** mutant
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

void 	SuperMutant::takeDamage(int dmg)
{
	if (dmg > 0)
		_hp -= (dmg / 3);
}