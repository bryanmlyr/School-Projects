/*
** EPITECH PROJECT, 2018
** ex00
** File description:
** MEEEEEEEEDIC
*/

#include "Skat.hpp"
#include <iostream>

Skat::Skat()
{
	wow = "bob";
	nb = 15;
}

Skat::Skat(const std::string &name)
{
	wow = name;
	nb = 15;
}

Skat::Skat(const std::string &name, int stimPaks)
{
	wow = name;
	nb = stimPaks;
}

const std::string &Skat::name()
{
	const std::string &ret = wow;

	return (ret);
}

void	Skat::shareStimPaks(int number, int &stock)
{
	if (stock > nb) {
		std::cout << "Don't be greedy" << std::endl;
	} else {
		nb -= number;
		std::cout << "Keep the change." << std::endl;
	}
}

void	Skat::addStimPaks(unsigned int number)
{
	if (number == 0) {
		std::cout << "Hey boya, did you forget something?" << std::endl;
	}
	nb += number;
}

void	Skat::useStimPaks()
{
	if (nb > 0) {
		std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
		nb--;
	}
	else {
		std::cout << "Mediiiiiic" << std::endl;
	}
}

void	Skat::status()
{
	std::cout << "Soldier " << wow << " reporting " << nb << " stimpaks remaining sir!" << std::endl;
}