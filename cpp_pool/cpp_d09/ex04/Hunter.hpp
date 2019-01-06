/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** hunter
*/

#ifndef HUNTER_HPP_
	#define HUNTER_HPP_

#include "Warrior.hpp"

class	Hunter : virtual public Warrior {
	public:
		Hunter(const std::string &, int);
		int CloseAttack();
		int RangeAttack();
		void Heal();
		void RestorePower();
};

#endif /* !HUNTER_HPP_ */
