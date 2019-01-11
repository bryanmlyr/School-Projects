/*
** EPITECH PROJECT, 2018
** A rolling Carpet
** File description:
** IConveyorBelt
*/

#ifndef ICONVERYORBELT_HPP_
	#define ICONVERYORBELT_HPP_

#include <vector>
#include "object.hpp"
#include "Wrap.hpp"

class	IConveyorBelt
{
	public:
		virtual ~IConveyorBelt() {}
		virtual void			put(Object *) = 0;
		virtual Object			*take() = 0;
		virtual Wrap			*pressButtonIN() = 0;
		virtual Object			*pressButtonOUT() = 0;
	protected:
		std::vector<Object *>		_objs;
};

#endif /* !ICONVERYORBELT_HPP_ */
