/*
** EPITECH PROJECT, 2018
** Elf
** File description:
** Elf
*/

#include "Elf.hpp"

Elf::Elf()
{
	_table = new PapaXmasTable();
	_conveyor = new PapaXmasConveyorBelt();
}

Elf::~Elf()
{}

Object	*Elf::wrap_gift(Object *to_wrap)
{
	if (to_wrap) {
		Object	*box = new Box();
		Object	*paper = new GiftPaper();
		box->openMe();
		box->wrapMeThat(to_wrap);
		paper->wrapMeThat(box);
		return paper;
	}
	return nullptr;
}

void	Elf::close_box(Object *new_obj)
{
	new_obj->closeMe();
}

void	Elf::open_box(Object *new_obj)
{
	new_obj->openMe();
}

void	Elf::close_wrap(Object *new_obj)
{
	new_obj->closeMe();
}

void	Elf::open_wrap(Object *new_obj)
{
	new_obj->openMe();
}

void	Elf::putOnTable(Object *new_obj)
{
	if (_table)
		_table->put(new_obj);
}

Object	*Elf::takeFromTable(int index)
{
	return _table->take(index);
}

void	Elf::putOnConveyor(Object *new_elem)
{
	_conveyor->put(new_elem);
}

Object	*Elf::takeFromConveyor()
{
	return _conveyor->take();
}

void	Elf::SendWrap()
{
	_conveyor->put(this->wrap_gift(_conveyor->pressButtonIN()));
	_conveyor->pressButtonOUT();
}

void	Elf::LookTable()
{
	std::vector<Object *> table = _table->lookTable();
	if (!_table->isBroken()) {
		for (unsigned int x = 0; x < table.size(); x++) {
			std::cout << table.at(x)->getTitle() << std::endl;
		}
	}
}