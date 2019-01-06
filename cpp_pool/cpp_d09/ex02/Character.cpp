/*
** EPITECH PROJECT, 2018
** pscine
** File description:
** ex00
*/

#include "Character.hpp"

Character::Character(const std::string &str, int lvl)
{
	name = str;
	level = lvl;
	pv = 100;
	energy = 100;
	Strengh = 5;
	Intelligence = 5;
	Stamina = 5;
	Spirit = 5;
	Agility = 5;
	dmg = 0;
	Race = "Koala";
	Range = Character::CLOSE;
	std::cout << name << " Created" << std::endl;
}

const std::string &Character::getName() const
{
	const std::string &wow = name;
	return wow;
}

int	Character::getLvl() const
{
	return level;
}

int	Character::getPv() const
{
	return pv;
}

int	Character::getPower() const
{
	return energy;
}

int	Character::CloseAttack()
{
	int	dmg = 0;

	if (energy - 10 >= 0) {
		Range = Character::CLOSE;
		dmg = Strengh + 10;
		std::cout << name << " strikes with a wooden stick" << std::endl;
		energy -= 10;
	}
	if (energy - 10 < 0) {
		dmg = 0;
		std::cout << name << " out of power" << std::endl;
	}
	return dmg;
}

int	Character::RangeAttack()
{
	int	dmg = 0;

	if (energy - 10 >= 0) {
		Range = Character::RANGE;
		dmg = Strengh + 5;
		std::cout << name << " tosses a stone" << std::endl;
		energy -= 10;
	}
	if (energy - 10 < 0) {
		dmg = 0;
		std::cout << name << " out of power" << std::endl;
	}
	return dmg;
}

void	Character::Heal()
{
	if (pv + 50 > 100)
		pv = 100;
	else
		pv += 50;
	std::cout << name << " takes a potion" << std::endl;
}

void	Character::RestorePower()
{
	energy = 100;
	std::cout << name << " eats" << std::endl;
}

void	Character::TakeDamage(int dmg)
{
	if (pv - dmg <= 0) {
		std::cout << name << " out of combat" << std::endl;
	} else {
		std::cout << name << " takes " << dmg << " damage" << std::endl;
	}
	pv -= dmg;
}