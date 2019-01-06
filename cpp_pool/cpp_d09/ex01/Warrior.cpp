/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** Warriror
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &str, int lvl) : Character(str, lvl)
{
	weapon = "hammer";
	Race = "Dwarf";
	Strengh = 12;
	Stamina = 12;
	Intelligence = 6;
	Spirit = 5;
	Agility = 7;
	Range = Character::CLOSE;
	std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int	Warrior::CloseAttack()
{
	int	dmg = 0;

	if (energy - 30 >= 0) {
		Range = Character::CLOSE;
		dmg = Strengh + 20;
		std::cout << name << " strikes with his " << weapon << std::endl;
		energy -= 30;
	}
	if (energy - 30 < 0) {
		dmg = 0;
		std::cout << name << " out of power" << std::endl;
	}
	return dmg;
}

int	Warrior::RangeAttack()
{
	int	dmg = 0;

	if (energy - 10 >= 0) {
		Range = Character::CLOSE;
		std::cout << name << " intercepts" << std::endl;
		energy -= 10;
	}
	if (energy - 10 < 0) {
		dmg = 0;
		std::cout << name << " out of power" << std::endl;
	}
	return dmg;
}

void	Warrior::Heal()
{
	Character::Heal();
}

void	Warrior::RestorePower()
{
	Character::RestorePower();
}