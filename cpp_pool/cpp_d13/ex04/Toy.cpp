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
	setAscii(path);
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

const Toy	&Toy::operator=(const Toy &toCopy)
{
	const Toy &wow = Toy(toCopy);
	return wow;
}

void		Toy::speak(const std::string &input)
{
	std::cout << Toy::getName() << " \"" << input << "\"" << std::endl;
}

std::ostream	&operator<<(std::ostream &input, Toy &newToy)
{
	input << newToy.getName() << std::endl << newToy.getAscii() << std::endl;
	return input;
}

Toy	&Toy::operator<<(const std::string &newAscii)
{
	_picture.data = newAscii;
	return *this;
}