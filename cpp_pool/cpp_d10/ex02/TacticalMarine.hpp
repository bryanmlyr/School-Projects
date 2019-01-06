/*
** EPITECH PROJECT, 2018
** pool
** File description:
** tactical
*/

#ifndef TACTICALMARINE_HPP_
	#define TACTICALMARINE_HPP_

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine {
	public:
		TacticalMarine();
		~TacticalMarine();
		ISpaceMarine *clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

#endif /* !TACTICALMARINE_HPP_ */
