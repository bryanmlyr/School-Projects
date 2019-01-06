/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** priest
*/

#ifndef PRIEST_HPP_
	#define PRIEST_HPP_

#include "Character.hpp"
#include "Mage.hpp"

class	Priest : public Mage {
	public:
		Priest(const std::string &, int);
		int CloseAttack();
		int RangeAttack();
		void Heal();
};

#endif /* !PRIEST_HPP_ */
