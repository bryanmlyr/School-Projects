/*
** EPITECH PROJECT, 2018
** Piscine jour7m
** File description:
** ex00
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
	_stability = true;
}

bool	WarpSystem::QuantumReactor::isStable()
{
	return _stability;
}

void	WarpSystem::QuantumReactor::setStability(bool in)
{
	_stability = in;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *in)
{
	_coreReactor = in;
}

WarpSystem::QuantumReactor	*WarpSystem::Core::checkReactor()
{
	return _coreReactor;
}