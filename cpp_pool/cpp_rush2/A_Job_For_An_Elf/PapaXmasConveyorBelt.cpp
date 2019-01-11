/*
** EPITECH PROJECT, 2018
** PapaXmasConveyorBelt
** File description:
** A rolling carpet
*/

#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{}

void	PapaXmasConveyorBelt::put(Object *new_obj)
{
	if (_objs.empty() && new_obj) {
		_objs.push_back(new_obj);
	} else if (!_objs.empty()) {
		std::cerr << "You can put only one"
		<< " object on the conveyor belt" << std::endl;
	} else {
		std::cerr << "Unvalid object" << std::endl;
	}
}

Object	*PapaXmasConveyorBelt::take()
{
	if (_objs.size() == 1 && _objs.at(0)) {
		Object *ret = new Object();
		ret = _objs.at(0);
		_objs.erase(_objs.begin());
		return ret;
	} else {
		std::cerr << "There is nothing on the conveyor belt" << std::endl;
		return nullptr;
	}
}

Object	*PapaXmasConveyorBelt::pressButtonIN()
{
	if (_objs.size() == 1 && _objs.at(0)) {
		Object *ret = new Object();
		ret = _objs.at(0);
		_objs.erase(_objs.begin());
		return ret;
	}
	return nullptr;
}

Object	*PapaXmasConveyorBelt::pressButtonOUT()
{
	if (_objs.size() == 1 && _objs.at(0)) {
		Object *ret = _objs.at(0);
		_objs.erase(_objs.begin());
		std::cout << "Gift send to Santa" << std::endl;
		return ret;
	}
	return nullptr;
}