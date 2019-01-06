/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** peon
*/

#include "Peon.hpp"

Peon::Peon(const std::string &name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void	Peon::getPolymorphed() const
{
	std::cout << _name << " has been turned into a pink pony!" << std::endl;
}