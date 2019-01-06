/*
** EPITECH PROJECT, 2018
** po
** File description:
** enemy
*/

#ifndef AENEMY_HPP_
	#define AENEMY_HPP_

#include <string>

class AEnemy {
	public:
		AEnemy(int, const std::string &);
		virtual ~AEnemy();
		virtual void takeDamage(int);
		std::string const &getType() const;
		int getHP() const;
	protected:
		int			_hp;
		std::string		_type;
};

#endif /* !AENEMY_HPP_ */
