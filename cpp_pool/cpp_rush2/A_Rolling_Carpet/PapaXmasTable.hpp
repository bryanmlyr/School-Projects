/*
** EPITECH PROJECT, 2018
** Rolling carpet
** File description:
** Table
*/

#ifndef PAPAXMASTABLE_HPP_
	#define PAPAXMASTABLE_HPP_

#include "ITable.hpp"

class PapaXmasTable : public ITable
{
	public:
		~PapaXmasTable();
		void			put(Object *);
		Object			*take(int);
		std::vector<Object *>	lookTable();
};

#endif /* !PAPAXMASTABLE_HPP_ */
