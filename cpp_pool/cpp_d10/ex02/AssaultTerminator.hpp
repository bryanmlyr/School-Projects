/*
** EPITECH PROJECT, 2018
** pool
** File description:
** Assault
*/

#ifndef ASSAULTTERMINATOR_HPP_
	#define ASSAULTTERMINATOR_HPP_

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine {
	public:
		AssaultTerminator();
		~AssaultTerminator();
		ISpaceMarine *clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

#endif /* !ASSAULTTERMINATOR_HPP_ */
