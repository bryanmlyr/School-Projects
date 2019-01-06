/*
** EPITECH PROJECT, 2018
** piscine cpp
** File description:
** droid ex00
*/

#include "Droid.hpp"
#include <iostream>

Droid::Droid(Droid const &wow) : Id(wow.Id), Energy(wow.Energy), Attack(wow.Attack), Toughness(wow.Toughness), Status(new std::string(*wow.Status))
{
	std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
	BattleData = new DroidMemory;
}

Droid::Droid(std::string serial) : Id(serial), Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
	std::cout << "Droid '" << Id << "' Activated" << std::endl;
	BattleData = new DroidMemory;
}

Droid::~Droid()
{
	std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
	delete Status;
	delete BattleData;
}

void	Droid::setId(std::string new_id)
{
	Id = new_id;
}

std::string	Droid::getId()
{
	return Id;
}

void	Droid::setEnergy(size_t new_energy)
{
	Energy = new_energy;
}

size_t	Droid::getEnergy() const
{
	return Energy;
}

size_t	Droid::getAttack() const
{
	return Attack;
}

size_t	Droid::getToughness() const
{
	return Toughness;
}

void	Droid::setStatus(std::string *new_status)
{
	Status = new_status;
}

std::string	*Droid::getStatus() const
{
	return Status;
}

bool	Droid::operator==(Droid const &other) const
{
	return (Id == other.Id && Energy == other.Energy && Toughness == other.Toughness && Status == other.Status);
}

bool	Droid::operator!=(Droid const &other) const
{
	return !(Id == other.Id && Energy == other.Energy && Toughness == other.Toughness && Status == other.Status);
}

Droid	&Droid::operator=(Droid const &wow)
{
	this->Id = wow.Id;
	this->Energy = wow.Energy;
	if (this->Status)
		delete this->Status;
	this->BattleData = new DroidMemory(*wow.BattleData);
	this->Status = new std::string(*wow.Status);
	return *this;
}

void	Droid::operator<<(size_t other)
{
	size_t	tmp;

	if (Energy < 100) {
		tmp = 100 - Energy;
		if (other >= tmp) {
			Energy += tmp;
			other -= tmp;
		} else {
			Energy += other;
			other = 0;
		}
	}
}

std::ostream	&operator<<(std::ostream &s, Droid &d)
{
	s << "Droid '" << d.getId() << "', " << *d.getStatus() << ", " << d.getEnergy();
	return s;
}

void	Droid::setBattleData(DroidMemory *mem)
{
	BattleData = mem;
}

DroidMemory	*Droid::getBattleData()
{
	return BattleData;
}