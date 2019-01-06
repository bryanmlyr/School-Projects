/*
** EPITECH PROJECT, 2018
** Exercise 0
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
	_type = BASIC_TOY;
	_toyName = "toy";
	_picture = Picture();
}

Toy::Toy(ToyType toy, const std::string &name, const std::string &path)
{
	_type = toy;
	_toyName = name;
	_picture = Picture(path);
}

Toy::~Toy()
{}

Toy::ToyType Toy::getType() const
{
	return _type;
}

std::string	Toy::getName() const
{
	return _toyName;
}

void		Toy::setName(const std::string &newName)
{
	_toyName = newName;
}

bool		Toy::setAscii(const std::string &path)
{
	_picture = Picture(path);
	return _picture.getPictureFromFile(path);
}

std::string	Toy::getAscii() const
{
	return _picture.data;
}