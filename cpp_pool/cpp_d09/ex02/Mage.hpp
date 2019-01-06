/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** mage
*/

#ifndef MAGE_HPP_
	#define MAGE_HPP_

#include "Character.hpp"

class	Mage : virtual public Character {
	public:
		Mage(const std::string &, int);
		int CloseAttack();
		int RangeAttack();
		void Heal();
		void RestorePower();
};

#endif /* !MAGE_HPP_ */
