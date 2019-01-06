/*
** EPITECH PROJECT, 2018
** Piscine
** File description:
** warrior
*/

#ifndef WARRIOR_HPP_
	#define WARRIOR_HPP_

#include "Character.hpp"

class	Warrior : virtual public Character {
	public:
		Warrior(const std::string &, int);
		int CloseAttack();
		int RangeAttack();
		void Heal();
		void RestorePower();
	protected:
		std::string	weapon;
};

#endif /* !WARRIOR_HPP_ */
