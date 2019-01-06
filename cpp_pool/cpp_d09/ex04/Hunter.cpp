/*
** EPITECH PROJECT, 2018
** Hunter
** File description:
** piscine
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &str, int lvl) : Character(str, lvl), Warrior(str, lvl)
{
	weapon = "sword";
	Race = "Elf";
	Strengh = 9;
	Stamina = 9;
	Intelligence = 5;
	Spirit = 6;
	Agility = 25;
	std::cout << name << " is born from a tree" << std::endl;
}

int	Hunter::CloseAttack()
{
	return Warrior::CloseAttack();
}

int	Hunter::RangeAttack()
{
	int dmg = 0;

	if (energy - 25 > 0) {
		dmg = 20 + Agility;
		energy -= 25;
		std::cout << name << " uses his bow" << std::endl;
	} else {
		dmg = 0;
		std::cout << name << " out of power" << std::endl;
	}
	return dmg;
}

void	Hunter::Heal()
{
	Warrior::Heal();
}

void	Hunter::RestorePower()
{
	energy = 100;
	std::cout << name << " meditates" << std::endl;
}