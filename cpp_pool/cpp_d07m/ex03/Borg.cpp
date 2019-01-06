/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** borg
*/

#include "Borg.hpp"
#include <iostream>

Borg::Ship::Ship(int wf)
{
	_home = UNICOMPLEX;
	_location = UNICOMPLEX;
	_shield = 100;
	_weaponFrequency = wf;
	_repair = 3;

	std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl << "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int wf, short rp)
{
	_home = UNICOMPLEX;
	_location = UNICOMPLEX;
	_shield = 100;
	_weaponFrequency = wf;
	_repair = rp;

	std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl << "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
}

void	Borg::Ship::setupCore(WarpSystem::Core *new_core)
{
	_our_core = new_core;
}

void	Borg::Ship::checkCore()
{
	if (_our_core->checkReactor()->isStable() == true)
		std::cout << "Everything is in order." << std::endl;
	else
		std::cout << "Critical failure imminent." << std::endl;
}

bool	Borg::Ship::move(int warp, Destination d)
{
	if (warp <= _maxWarp && d != _location && _our_core->checkReactor()->isStable() == true) {
		_location = d;
		return true;
	}
	return false;
}

bool	Borg::Ship::move(int warp)
{
	if (warp <= _maxWarp && _our_core->checkReactor()->isStable() == true) {
		_location = _home;
		return true;
	}
	return false;
}

bool	Borg::Ship::move(Destination d)
{
	if (d != _location && _our_core->checkReactor()->isStable() == true) {
		_location = d;
		return true;
	}
	return false;
}

bool	Borg::Ship::move()
{
	if (_our_core->checkReactor()->isStable() == true) {
		_location = _home;
		return true;
	}
	return false;
}

int	Borg::Ship::getShield()
{
	return _shield;
}

void	Borg::Ship::setShield(int sh)
{
	_shield = sh;
}

int	Borg::Ship::getWeaponFrequency()
{
	return _weaponFrequency;
}

void	Borg::Ship::setWeaponFrequency(int fre)
{
	_weaponFrequency = fre;
}

short	Borg::Ship::getRepair()
{
	return _repair;
}

void	Borg::Ship::setRepair(short rp)
{
	_repair = rp;
}

void	Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
	target->setShield(target->getShield() - _weaponFrequency);
	std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}

void	Borg::Ship::fire(Federation::Ship *target)
{
	target->getCore()->checkReactor()->setStability(false);
	std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}

void	Borg::Ship::repair()
{
	if (_repair > 0) {
		_repair--;
		_shield = 100;
		std::cout << "Begin shield re-initialisation... Done. Awaiting further insctructions." << std::endl;
		return;
	}
	std::cout << "Energy cells depleted, shield weakening." << std::endl;
}