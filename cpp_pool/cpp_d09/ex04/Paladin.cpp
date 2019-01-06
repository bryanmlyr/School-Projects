/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &str, int lvl) : Character(str, lvl), Warrior(str, lvl), Priest(str, lvl)
{
	weapon = "hammer";
	Race = "Human";
	Strengh = 9;
	Stamina = 10;
	Intelligence = 10;
	Spirit = 10;
	Agility = 2;
	Range = Character::CLOSE;
	std::cout << "the light falls on " << Warrior::name << std::endl;
}

int	Paladin::CloseAttack()
{
	return Warrior::CloseAttack();
}

int	Paladin::RangeAttack()
{
	return Priest::RangeAttack();
}

void	Paladin::Heal()
{
	Priest::RangeAttack();
}

void	Paladin::RestorePower()
{
	Warrior::RestorePower();
}

int	Paladin::Intercept()
{
	return Warrior::RangeAttack();
}