/*
** EPITECH PROJECT, 2018
** Ex3
** File description:
** simplePtr
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr)
{
	_rawPtr = rawPtr;
}

BaseComponent	*SimplePtr::get() const
{
	return _rawPtr;
}