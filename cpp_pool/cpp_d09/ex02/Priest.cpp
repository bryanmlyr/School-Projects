/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &str, int lvl) : Character(str, lvl), Mage(str, lvl)
{
	Race = "Orc";
	Strengh = 4;
	Stamina = 4;
	Intelligence = 42;
	Spirit = 21;
	Agility = 2;
	Range = Character::CLOSE;
	std::cout << name << " enters in the order" << std::endl;
}

int	Priest::CloseAttack()
{
	int	dmg = 0;

	if (energy - 10 >= 0) {
		Range = Character::CLOSE;
		dmg = 10 + Spirit;
		std::cout << name << " uses a spirit explosion" << std::endl;
		energy -= 10;
	}
	if (energy - 10 < 0) {
		dmg = 0;
		std::cout << name << " out of power" << std::endl;
	}
	return dmg;
}

int	Priest::RangeAttack()
{
	int	dmg = 0;

	if (energy - 25 >= 0) {
		Range = Character::RANGE;
		dmg = 20 + Spirit;
		std::cout << name << " launches a fire ball" << std::endl;
		energy -= 25;
	}
	if (energy - 25 < 0) {
		dmg = 0;
		std::cout << name << " out of power" << std::endl;
	}
	return dmg;
}

void	Priest::Heal()
{
	if (energy - 10 >= 0) {
		if (pv + 70 <= 100)
			pv += 70;
		else
			pv = 100;
		std::cout << name << " casts a little heal spell" << std::endl;
	} else {
		std::cout << name << " out of power" << std::endl;
	}
}