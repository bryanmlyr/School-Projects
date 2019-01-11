/*
** EPITECH PROJECT, 2018
** A box story
** File description:
** box
*/

#ifndef BOX_HPP_
	#define BOX_HPP_

#include "Wrap.hpp"

class Box : public Wrap
{
	public:
		Box();
		void wrapMeThat(Object *);
};

#endif /* !BOX_HPP_ */
