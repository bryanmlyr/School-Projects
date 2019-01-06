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
	_last = UNKNOWN;
}

Toy::Toy(ToyType toy, const std::string &name, const std::string &path)
{
	_type = toy;
	_toyName = name;
	setAscii(path);
	_last = UNKNOWN;
}

Toy::~Toy()
{}

Toy::ToyType Toy::getType() const
{
	return _type;
}

std::string	Toy::getName()
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
	if (_picture.getPictureFromFile(path) == false)
		_last = PICTURE;
	return _picture.getPictureFromFile(path);
}

std::string	Toy::getAscii()
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

bool	Toy::speak_es(const std::string &str)
{
	(void) str;
	_last = SPEAK;
	return false;
}

Toy::Error::Error(Toy::LastError last)
{
	if (last == 0)
		type = UNKNOWN;
	if (last == 1)
		type = PICTURE;
	if (last == 2)
		type = SPEAK;
}

std::string	Toy::Error::what() const
{
	if (type == PICTURE) {
		return "bad new illustration";
	} else if (type == SPEAK) {
		return "wrong mode";
	} else {
		return "";
	}
}

std::string	Toy::Error::where() const
{
	if (type == PICTURE) {
		return "setAscii";
	} else if (type == SPEAK) {
		return "speak_es";
	} else {
		return "";
	}
}

Toy::Error Toy::getLastError()
{
	return Toy::Error(_last);
}