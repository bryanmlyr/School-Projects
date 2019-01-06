/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** ex00
*/

#ifndef CHARACATER_HPP_
	#define CHARACATER_HPP_

#include <string>
#include <iostream>

class	Character {
	public:
		Character(const std::string &, int);
		const std::string &getName() const;
		int getLvl() const;
		int getPv() const;
		int getPower() const;
		enum AttackRange{CLOSE, RANGE};
		int CloseAttack();
		void Heal();
		int RangeAttack();
		void RestorePower();
		void TakeDamage(int);
		AttackRange	Range;
	protected:
		std::string	name;
		int		level;
		int		pv;
		int		energy;
		std::string	Race;
		int		Intelligence;
		int		Strengh;
		int		Stamina;
		int		Spirit;
		int		Agility;
		int		dmg;
};

#endif /* !CHARACATER_HPP_ */
