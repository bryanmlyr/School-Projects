/*
** EPITECH PROJECT, 2018
** Rolling Carpet
** File description:
** ConveyorBelt
*/

#ifndef PAPAXMASCONVEYORBELT_HPP_
	#define PAPAXMASCONVEYORBELT_HPP_

#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt
{
	public:
		~PapaXmasConveyorBelt();
		void	put(Object *);
		Object	*take();
		Object	*pressButtonIN();
		Object	*pressButtonOUT();
};

#endif /* !PAPAXMASCONVEYORBELT_HPP_ */
