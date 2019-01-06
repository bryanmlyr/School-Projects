/*
** EPITECH PROJECT, 2018
** pool
** File description:
** Char
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name)
{
	_ap = 40;
}

void	Character::equip(AWeapon *weap)
{
	_Weapon = weap;
}

void	Character::attack(AEnemy *en)
{
	if (en && _Weapon && _ap >= _Weapon->getAPCost() && en->getHP() > 0) {
		_ap -= _Weapon->getAPCost();
		std::cout << _name << " attacks " << en->getType() << " with a " << _Weapon->getName() << std::endl;
		en->takeDamage(_Weapon->getDamage());
		_Weapon->attack();
		if (en->getHP() <= 0)
			delete en;
	}
}

void	Character::recoverAP()
{
	if (_ap + 10 < 40)
		_ap += 10;
}

const std::string &Character::getName() const
{
	return _name;
}

AWeapon	*Character::getWeapon() const
{
	return _Weapon;
}

int	Character::getAP() const
{
	return _ap;
}

std::ostream	&operator<<(std::ostream &s, Character &ch)
{
	if (ch.getWeapon()) {
		AWeapon *temp = ch.getWeapon();
		s << ch.getName() << " has " << ch.getAP() << " AP and wields a " << temp->getName() << std::endl;
	} else {
		s << ch.getName() << " has " << ch.getAP() << " AP and is unarmed" << std::endl;
	}
	return s;
}