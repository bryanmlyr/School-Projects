/*
** EPITECH PROJECT, 2018
** rush02
** File description:
** LittlePony And Teddy
*/

#include "teddy.hpp"

Teddy::Teddy(const std::string &title)
	: Toy(title)
{}

void	Teddy::isTaken()
{
	if (_taken == true)
		std::cout << "gra hu" << std::endl;
}
