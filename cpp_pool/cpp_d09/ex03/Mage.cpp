/*
** EPITECH PROJECT, 2018
** piscinec cpp
** File description:
** Magr
*/

#include "Mage.hpp"

Mage::Mage(const std::string &str, int lvl) : Character(str, lvl)
{
	Race = "Gnome";
	Strengh = 6;
	Stamina = 6;
	Intelligence = 12;
	Spirit = 11;
	Agility = 7;
	Range = Character::CLOSE;
	std::cout << name << " teleported" << std::endl;
}

int	Mage::CloseAttack()
{
	int	dmg = 0;

	if (energy - 10 >= 0) {
		dmg = 0;
		std::cout << name << " blinks" << std::endl;
		energy -= 10;
		Range = Character::RANGE;
	}
	if (energy - 10 < 0) {
		dmg = 0;
		std::cout << name << " out of power" << std::endl;
	}
	return dmg;
}

int	Mage::RangeAttack()
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

void	Mage::Heal()
{
	Character::Heal();
}

void	Mage::RestorePower()
{
	if (energy + 50 + Intelligence > 100)
		energy = 100;
	else
		energy += 50 + Intelligence;
	std::cout << name << " takes a mana potion" << std::endl;
}