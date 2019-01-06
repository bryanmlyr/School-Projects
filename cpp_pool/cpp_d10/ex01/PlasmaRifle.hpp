/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** plasma
*/

#ifndef PLASMARIFLE_HPP_
	#define PLASMARIFLE_HPP_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		void attack() const ;
};

#endif /* !PLASMARIFLE_HPP_ */
