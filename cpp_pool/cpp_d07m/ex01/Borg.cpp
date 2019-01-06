/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** borg
*/

#include "Borg.hpp"
#include <iostream>

Borg::Ship::Ship()
{
	std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl << "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
}

void	Borg::Ship::setupCore(WarpSystem::Core *new_core)
{
	_our_core = new_core;
}

void	Borg::Ship::checkCore()
{
	if (_our_core->checkReactor()->isStable() == true)
		std::cout << "Everything is in order." << std::endl;
	else
		std::cout << "Critical failure imminent." << std::endl;
}
