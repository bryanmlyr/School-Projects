/*
** EPITECH PROJECT, 2018
** pool
** File description:
** anemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : _hp(hp), _type(type)
{
}

AEnemy::~AEnemy()
{
}

void	AEnemy::takeDamage(int damage)
{
	if (damage >= 0)
		_hp -= damage;
}

const std::string &AEnemy::getType() const
{
	return _type;
}

int	AEnemy::getHP() const
{
	return _hp;
}