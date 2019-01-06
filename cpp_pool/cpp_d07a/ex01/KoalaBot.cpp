/*
** EPITECH PROJECT, 2018
** koala style
** File description:
** koala
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot()
{
	_serial = "Bob-01";
}

void	KoalaBot::setParts(Arms &a1)
{
	this->a1 = a1;
}

void	KoalaBot::setParts(Legs &l1)
{
	this->l1 = l1;
}

void	KoalaBot::setParts(Head &h1)
{
	this->h1 = h1;
}

void	KoalaBot::swapParts(Arms &a1, Arms &a2)
{
	Arms	temp = a1;

	a1 = a2;
	a2 = temp;
}

void	KoalaBot::swapParts(Legs &l1, Legs &l2)
{
	Legs	temp = l1;

	l1 = l2;
	l2 = temp;
}

void	KoalaBot::swapParts(Head &h1, Head &h2)
{
	Head	temp = h1;

	h1 = h2;
	h2 = temp;
}

void	KoalaBot::informations()
{
	std::cout << "[KoalaBot] " << _serial << std::endl;
	a1.informations();
	l1.informations();
	h1.informations();
}

bool	KoalaBot::status()
{
	return (a1.isFunctionnal() && l1.isFunctionnal() && h1.isFunctionnal());
}