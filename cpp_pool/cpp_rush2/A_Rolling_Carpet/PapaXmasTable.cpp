/*
** EPITECH PROJECT, 2018
** PapaXmas
** File description:
** A rolling carpet
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::~PapaXmasTable()
{}

void	PapaXmasTable::put(Object *new_obj)
{
	if (new_obj && _objs.size() + 1 <= 10) {
		_objs.push_back(new_obj);
	} else if (_objs.size() + 1 > 10) {
		std::cerr << "Voila you just broke the table" << std::endl;
		delete this;
	} else {
		std::cerr << "Unvalid Object" << std::endl;
	}
}

Object	*PapaXmasTable::take(int index)
{
	Object	*temp;

	if (index < (int)_objs.size() && index >= 0 && _objs.size() != 0) {
		temp = _objs.at(index);
		_objs.erase(_objs.begin() + index);
		return temp;
	} else {
		std::cerr << "Out of range" << std::endl;
		return nullptr;
	}
}

std::vector<Object *>	PapaXmasTable::lookTable()
{
	return	_objs;
}