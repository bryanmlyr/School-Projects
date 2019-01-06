/*
** EPITECH PROJECT, 2018
** piscine cpp
** File description:
** droid ex00
*/

#ifndef DROID_HPP_
	#define DROID_HPP_

#include "DroidMemory.hpp"
#include <string>
#include <iostream>

class Droid
{
	public:
		Droid(Droid const &);
		Droid(std::string);
		~Droid();
		void		setId(std::string);
		std::string	getId();
		void		setEnergy(size_t);
		size_t		getEnergy() const;
		size_t		getAttack() const;
		size_t		getToughness() const;
		void		setStatus(std::string *);
		std::string	*getStatus() const;
		DroidMemory	*getBattleData();
		void		setBattleData(DroidMemory *);
		bool 		operator==(Droid const &) const;
		bool 		operator!=(Droid const &) const;
		void 		operator<<(size_t);
		Droid 		&operator=(Droid const &);
	private:
		std::string	Id;
		size_t		Energy;
		const size_t	Attack;
		const size_t	Toughness;
		std::string	*Status;
		DroidMemory	*BattleData;
};

std::ostream	&operator<<(std::ostream &, Droid &);

#endif /* !DROID_HPP_ */
