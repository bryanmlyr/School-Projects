/*
** EPITECH PROJECT, 2018
** A box story
** File description:
** box
*/

#include "Box.hpp"

Box::Box() : Wrap()
{}

void	Box::wrapMeThat(Object *obj)
{
	if (_Opened && _Obj == nullptr && obj != nullptr) {
		std::cout << "tuuuut tuuut tuut" << std::endl;
		_Obj = obj;
	} else if (_Opened == false){
		std::cerr << "Box is closed" << std::endl;
	} else {
		std::cerr << "The object already contains something" << std::endl;
	}
}