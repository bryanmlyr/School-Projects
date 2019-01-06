/*
** EPITECH PROJECT, 2018
** squad
** File description:
** pool
*/

#ifndef SQUAD_HPP_
	#define SQUAD_HPP_

#include <vector>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {
	public:
		~Squad();
		int getCount() const;
		ISpaceMarine *getUnit(int);
		int push(ISpaceMarine *);
		Squad operator=(const Squad &);
	private:
		std::vector<ISpaceMarine *> _spm;
};

#endif /* !SQUAD_HPP_ */
