/*
** EPITECH PROJECT, 2018
** A box story
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() : Wrap()
{}

void	GiftPaper::wrapMeThat(Object *obj)
{
	if (_Obj == nullptr && obj != nullptr) {
		std::cout << "tuuuut tuuut tuut" << std::endl;
		_Obj = obj;
	} else {
		std::cerr << "The object already contains something" << std::endl;
	}
}