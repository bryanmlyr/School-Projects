/*
** EPITECH PROJECT, 2018
** pool
** File description:
** supermutant
*/

#ifndef SUPERMUTANT_HPP_
	#define SUPERMUTANT_HPP_

#include <iostream>
#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
	public:
		SuperMutant();
		~SuperMutant();
		void takeDamage(int);
};

#endif /* !SUPERMUTANT_HPP_ */
