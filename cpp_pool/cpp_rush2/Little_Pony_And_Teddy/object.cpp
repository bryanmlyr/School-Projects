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

void    Object::setTaken(bool new_stat)
{
        _taken = new_stat;
}

std::string Object::getTitle() const
{
        return _title;
}
