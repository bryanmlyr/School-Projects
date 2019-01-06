/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** ex00
*/

#include "Federation.hpp"
#include <iostream>

Federation::Starfleet::Ship::Ship(int l = 289, int w = 132, std::string n = "Entreprise", short mw = 6, int torpedo = 20)
{
	_lenght = l;
	_width = w;
	_name = n;
	_maxWarp = mw;
	_home = EARTH;
	_location = EARTH;
	_shield = 100;
	_photonTorpedo = torpedo;

	std::cout << "The ship USS " << _name << " has been finished. It is " << _lenght << " m in length and " << _width << " m in width. It can go to Warp " << _maxWarp << "! Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

void	Federation::Starfleet::Ship::setupCore(WarpSystem::Core *new_core)
{
	_our_core = new_core;
	std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void	Federation::Starfleet::Ship::checkCore()
{
	if (_our_core->checkReactor()->isStable() == true)
		std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
	else
		std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
}

Federation::Ship::Ship(int l, int w, std::string n)
{
	_lenght = l;
	_width = w;
	_name = n;
	_maxWarp = 1;
	_home = VULCAN;
	_location = VULCAN;

	std::cout << "The independant ship " << _name << " just finished its construction. It is " << _lenght << " m in length and " << _width << " m in width." << std::endl;
}

void	Federation::Ship::setupCore(WarpSystem::Core *new_core)
{
	_our_core = new_core;
	std::cout << _name << ": The core is set." << std::endl;
}

void	Federation::Ship::checkCore()
{
	if (_our_core->checkReactor()->isStable() == true)
		std::cout << _name << ": The core is stable at the time." << std::endl;
	else
		std::cout << _name << ": The core is unstable at the time." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string str)
{
	_name = str;
}

std::string	Federation::Starfleet::Captain::getName()
{
	return _name;
}

int		Federation::Starfleet::Captain::getAge()
{
	return age;
}

void		Federation::Starfleet::Captain::setAge(int new_age)
{
	age = new_age;
}

void		Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *new_cap)
{
	_our_captain = new_cap;
	std::cout << _our_captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string str)
{
	_name = str;
}

bool	Federation::Starfleet::Ship::move(int warp, Destination d)
{
	if (warp <= _maxWarp && d != _location && _our_core->checkReactor()->isStable() == true) {
		_location = d;
		return true;
	}
	return false;
}

bool	Federation::Starfleet::Ship::move(int warp)
{
	if (warp <= _maxWarp && _our_core->checkReactor()->isStable() == true) {
		_location = _home;
		return true;
	}
	return false;
}

bool	Federation::Starfleet::Ship::move(Destination d)
{
	if (d != _location && _our_core->checkReactor()->isStable() == true) {
		_location = d;
		return true;
	}
	return false;
}

bool	Federation::Starfleet::Ship::move()
{
	if (_our_core->checkReactor()->isStable() == true) {
		_location = _home;
		return true;
	}
	return false;
}

bool	Federation::Ship::move(int warp, Destination d)
{
	if (warp <= _maxWarp && d != _location && _our_core->checkReactor()->isStable() == true) {
		_location = d;
		return true;
	}
	return false;
}

bool	Federation::Ship::move(int warp)
{
	if (warp <= _maxWarp && _our_core->checkReactor()->isStable() == true) {
		_location = _home;
		return true;
	}
	return false;
}

bool	Federation::Ship::move(Destination d)
{
	if (d != _location && _our_core->checkReactor()->isStable() == true) {
		_location = d;
		return true;
	}
	return false;
}

bool	Federation::Ship::move()
{
	if (_our_core->checkReactor()->isStable() == true) {
		_location = _home;
		return true;
	}
	return false;
}

int	Federation::Starfleet::Ship::getShield()
{
	return _shield;
}

void	Federation::Starfleet::Ship::setShield(int shield)
{
	_shield = shield;
}

int	Federation::Starfleet::Ship::getTorpedo()
{
	return _photonTorpedo;
}

void	Federation::Starfleet::Ship::setTorpedo(int torp)
{
	_photonTorpedo = torp;
}

void	Federation::Starfleet::Ship::fire(int rocketos, Borg::Ship *target)
{
	if (_photonTorpedo == 0) {
		std::cout << _name << ": No more torpedo to fire, " << _our_captain->getName() << "!" << std::endl;
		return;
	}
	if (_photonTorpedo - rocketos <= 0) {
		std::cout << _name << ": No enough torpedoes to fire, " << _our_captain->getName() << "!" << std::endl;
		return;
	}
	std::cout << _name << ": Firing on target. " << _photonTorpedo - rocketos << " torpedoes remaining" << std::endl;
	target->setShield(target->getShield() - rocketos * 50);
}

void	Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
	int	rocketos = 1;

	if (_photonTorpedo == 0) {
		std::cout << _name << ": No more torpedo to fire, " << _our_captain->getName() << "!" << std::endl;
		return;
	}
	if (_photonTorpedo - rocketos <= 0) {
		std::cout << _name << ": No enough torpedoes to fire, " << _our_captain->getName() << "!" << std::endl;
		return;
	}
	std::cout << _name << ": Firing on target. " << _photonTorpedo - rocketos << " torpedoes remaining" << std::endl;
	target->setShield(target->getShield() - rocketos * 50);
}

WarpSystem::Core	*Federation::Ship::getCore()
{
	return _our_core;
}