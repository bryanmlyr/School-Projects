/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
{
	_name = name;
	_title = title;
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string	Sorcerer::getName()
{
	return _name;
}

std::string	Sorcerer::getTitle()
{
	return _title;
}

void		Sorcerer::polymorph(const Victim &victim) const
{
	victim.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &s, Sorcerer &sor)
{
	s << "I am " << sor.getName() << ", " << sor.getTitle() << ", and I like ponies!" << std::endl;
	return s;
}