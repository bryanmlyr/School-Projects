/*
** EPITECH PROJECT, 2018
** rush02
** File description:
** LittlePony And Teddy
*/

#include "littlepony.hpp"

LittlePony::LittlePony(const std::string &title)
	: Toy(title)
{}

void	LittlePony::isTaken()
{
	if (_taken == true)
		std::cout << "yo man" << std::endl;
}
