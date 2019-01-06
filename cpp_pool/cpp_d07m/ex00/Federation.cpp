/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** ex00
*/

#include "Federation.hpp"
#include <iostream>

Federation::Starfleet::Ship::Ship(int l, int w, std::string n, short mw)
{
	_lenght = l;
	_width = w;
	_name = n;
	_maxWarp = mw;

	std::cout << "The ship USS " << _name << " has been finished. It is " << _lenght << " m in length and " << _width << " m in width." << std::endl;
	std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

void	Federation::Starfleet::Ship::setupCore(WarpSystem::Core *new_core)
{
	_our_core = new_core;
	std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void	Federation::Starfleet::Ship::checkCore()
{
	if (_our_core->checkReactor()->isStable() == true)
		std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
	else
		std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
}

Federation::Ship::Ship(int l, int w, std::string n)
{
	_lenght = l;
	_width = w;
	_name = n;
	_maxWarp = 1;

	std::cout << "The independant ship " << _name << " just finished its construction. It is " << _lenght << " m in length and " << _width << " m in width." << std::endl;
}

void	Federation::Ship::setupCore(WarpSystem::Core *new_core)
{
	_our_core = new_core;
	std::cout << _name << ": The core is set." << std::endl;
}

void	Federation::Ship::checkCore()
{
	if (_our_core->checkReactor()->isStable() == true)
		std::cout << _name << ": The core is stable at the time." << std::endl;
	else
		std::cout << _name << ": The core is unstable at the time." << std::endl;
}