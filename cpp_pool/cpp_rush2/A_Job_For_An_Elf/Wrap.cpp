/*
** EPITECH PROJECT, 2018
** A box story
** File description:
** Warp
*/

#include "Wrap.hpp"

Wrap::Wrap() : Object(), _Opened(false), _Obj(nullptr)
{
	std::cout << "whistles while working" << std::endl;
}

void	Wrap::wrapMeThat(Object *new_elem)
{
	(void) new_elem;
}

void	Wrap::openMe()
{
	_Opened = true;
}

void	Wrap::closeMe()
{
	_Opened = false;
}

bool	Wrap::isOpen() const
{
	return _Opened;
}

void	Wrap::removeObject()
{
	_Obj = nullptr;
}