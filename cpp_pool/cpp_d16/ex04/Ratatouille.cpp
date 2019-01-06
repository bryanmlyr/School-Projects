/*
** EPITECH PROJECT, 2018
** Ratatouille
** File description:
** class
*/

#include "Ratatouille.hpp"

Ratatouille::Ratatouille()
{
}

Ratatouille::~Ratatouille()
{
}

Ratatouille &Ratatouille::operator=(const Ratatouille &new_rat)
{
	_str = new_rat._str;
	return *this;
}

Ratatouille &Ratatouille::addVegetable(unsigned char elem)
{
	std::ostringstream temp;

	temp << elem;
	_str.push_back(temp.str());
	return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int elem)
{
	std::ostringstream temp;

	temp << elem;
	_str.push_back(temp.str());
	return *this;
}

Ratatouille &Ratatouille::addSpice(double elem)
{
	std::ostringstream temp;

	temp << elem;
	_str.push_back(temp.str());
	return *this;
}

Ratatouille &Ratatouille::addSauce(const std::string &elem)
{
	std::ostringstream temp;

	temp << elem;
	_str.push_back(temp.str());
	return *this;
}

std::string Ratatouille::kooc()
{
	std::string ret = "";

	for (unsigned int x = 0; x < _str.size(); x++) {
		ret += _str.at(x);
	}
	return ret;
}