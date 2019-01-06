/*
** EPITECH PROJECT, 2018
** Exercise 2
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name) : Toy(BUZZ, name, "./buzz.txt")
{
}

Buzz::Buzz(const std::string &name, const std::string &path) : Toy(BUZZ, name, path)
{
}

Buzz::~Buzz()
{
}

void	Buzz::speak(const std::string &input)
{
	std::cout << "BUZZ: " << Toy::getName() << " \"" << input << "\"" << std::endl;
}