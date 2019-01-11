/*
** EPITECH PROJECT, 2018
** rush02
** File description:
** LittlePony And Teddy
*/

#include "object.hpp"

Object::Object(const std::string &title)
	: _title(title), _taken(false)
{}

void    Object::isTaken()
{}

Object::Object()
{}

Object::~Object()
{}

void	Object::wrapMeThat(Object *)
{}

void Object::openMe()
{}

void Object::closeMe()
{}

bool Object::isOpen() const
{
	return false;
}

void Object::removeObject()
{}

void    Object::setTaken(bool new_stat)
{
        _taken = new_stat;
}

std::string Object::getTitle() const
{
        return _title;
}
