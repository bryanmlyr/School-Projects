/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** wepon
*/

#ifndef AWEAPON_HPP_
	#define AWEAPON_HPP_

#include <string>
#include <iostream>

class AWeapon {
	public:
		AWeapon(const std::string &, int, int);
		virtual ~AWeapon();
		const std::string &getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
	private:
		std::string	_name;
		int		_apcost;
		int		_damage;
};

#endif /* !AWEAPON_HPP_ */
