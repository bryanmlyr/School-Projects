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
	if (_objs.size() == 1) {
		return _objs.at(0);
	} else {
		std::cerr << "There is nothing on the conveyor belt" << std::endl;
		return nullptr;
	}
}

Wrap	*PapaXmasConveyorBelt::pressButtonIN()
{
	if (_objs.size() == 1 && _objs.at(0)) {
		Wrap *ret = new Wrap();
		ret->wrapMeThat(_objs.at(0));
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
		return ret;
	}
	return nullptr;
}