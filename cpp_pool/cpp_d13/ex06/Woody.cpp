/*
** EPITECH PROJECT, 2018
** Exercise 2
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name) : Toy(WOODY, name, "./woody.txt")
{
}

Woody::Woody(const std::string &name, const std::string &path) : Toy(WOODY, name, path)
{
}

Woody::~Woody()
{
}

void	Woody::speak(const std::string &input)
{
	std::cout << "WOODY: " << Toy::getName() << " \"" << input << "\"" << std::endl;
}

bool	Woody::speak_es(const std::string &input)
{
	(void) input;
	_last = SPEAK;
	return false;
}