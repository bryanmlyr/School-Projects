/*
** EPITECH PROJECT, 2018
** Assault
** File description:
** ass
*/

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}

ISpaceMarine *AssaultTerminator::clone() const
{
	ISpaceMarine *ret = new AssaultTerminator();
	return ret;
}

void	AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void	AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void	AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}