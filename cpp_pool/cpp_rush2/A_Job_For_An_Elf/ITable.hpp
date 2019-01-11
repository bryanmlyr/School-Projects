/*
** EPITECH PROJECT, 2018
** A Rolling Carpet
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
	#define ITABLE_HPP_

#include <vector>
#include "object.hpp"

class ITable
{
	public:
		virtual 			~ITable() {}
		virtual void			put(Object *) = 0;
		virtual Object			*take(int) = 0;
		virtual std::vector<Object *>	lookTable() = 0;
		virtual bool			isBroken() = 0;
	protected:
		std::vector<Object *>		_objs;
};

#endif /* !ITABLE_HPP_ */
