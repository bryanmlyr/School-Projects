/*
** EPITECH PROJECT, 2018
** piscine paladin
** File description:
** paladin
*/

#ifndef PALADIN_HPP_
	#define PALADIN_HPP_

#include "Character.hpp"
#include "Warrior.hpp"
#include "Priest.hpp"

class	Paladin : public Warrior, public Priest {
	public:
		Paladin(const std::string &, int);
		int CloseAttack();
		int RangeAttack();
		void Heal();
		void RestorePower();
		int Intercept();
};

#endif /* !PALADIN_HPP_ */
