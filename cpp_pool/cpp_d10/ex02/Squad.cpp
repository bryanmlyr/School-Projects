/*
** EPITECH PROJECT, 2018
** squad
** File description:
** pool
*/

#include "Squad.hpp"

Squad::~Squad()
{
	int x = 0;
	int max = _spm.size();

	while (x < max) {
		if (_spm.at(x))
			delete _spm.at(x);
		x++;
	}
	_spm.clear();
}

int	Squad::getCount() const
{
	return _spm.size();
}

ISpaceMarine	*Squad::getUnit(int pos)
{
	return _spm.at(pos);
}

int		Squad::push(ISpaceMarine *n)
{
	if (n)
		_spm.push_back(n);
	return _spm.size();
}

Squad Squad::operator=(const Squad &sq)
{
	return Squad(sq);
}