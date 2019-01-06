//
// EPITECH PROJECT, 2018
// piscine cpp
// File description:
// SickKoala
//

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string str) : koala_name(str)
{
}

SickKoala::~SickKoala()
{
	std::cout << "Mr." << koala_name << ": Kreooogg!! I'm cuuuured!"
	<< std::endl;
}

void	SickKoala::poke()
{
	std::cout << "Mr." << koala_name << ": Gooeeeeerrk!! :'("
	<< std::endl;
}

bool	SickKoala::takeDrug(std::string str)
{
	if (str == "Buronzand") {
		std::cout << "Mr." << koala_name << ": And you'll sleep right away!"
		<< std::endl;
		return true;
	} else if (str.length() == 4 && (str[0] == 'm' || str[0] == 'M')
			&& (str[1] == 'a' || str[1] == 'A')
			&& (str[2] == 'r' || str[2] == 'R')
			&& (str[3] == 's' || str[3] == 'S')) {
		std::cout << "Mr." << koala_name << ": Mars, and it kreogs!"
		<< std::endl;
		return true;
	} else {
		std::cout << "Mr." << koala_name << ": Goerkreog!"
		<< std::endl;
		return false;
	}
}

void	SickKoala::overDrive(std::string str)
{
	std::string	new_str;

	new_str = std::regex_replace(str, std::regex("\\Kreog!"), "1337!");
	std::cout << "Mr." << koala_name << ": " << new_str << std::endl;
}