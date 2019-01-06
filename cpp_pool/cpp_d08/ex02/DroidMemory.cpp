/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** ex01
*/

#include "DroidMemory.hpp"
#include <iostream>

DroidMemory::DroidMemory()
{
	Exp = 0;
	FingerPrint = random();
}

size_t	DroidMemory::getFingerPrint()
{
	return FingerPrint;
}

size_t	DroidMemory::getExp()
{
	return Exp;
}

void	DroidMemory::setFingerPrint(size_t t)
{
	FingerPrint = t;
}

void	DroidMemory::setExp(size_t t)
{
	FingerPrint = t;
}

void	DroidMemory::operator<<(const DroidMemory &mem)
{
	FingerPrint ^= mem.FingerPrint;
	Exp += mem.Exp;
}

void	DroidMemory::operator>>(DroidMemory &mem)
{
	mem.FingerPrint ^= FingerPrint;
	mem.Exp += Exp;
}

void	DroidMemory::operator+=(size_t add)
{
	Exp += add;
	FingerPrint ^= Exp;
}

void	DroidMemory::operator+(const DroidMemory mem)
{
	FingerPrint ^= mem.FingerPrint;
	Exp += mem.Exp;
}

DroidMemory	DroidMemory::operator+(size_t add)
{
	Exp += add;
	FingerPrint ^= Exp;
	return *this;
}

std::ostream	&operator<<(std::ostream &s, DroidMemory mem)
{
	s << "Droid Memory '" << mem.getFingerPrint() << "', " << mem.getExp() << std::endl;
	return s;
}