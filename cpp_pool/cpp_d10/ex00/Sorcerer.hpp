/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** sorcerer
*/

#ifndef SORCERER_HPP_
	#define SORCERER_HPP_

#include "Victim.hpp"

class Sorcerer {
	public:
		Sorcerer(const std::string &, const std::string &);
		~Sorcerer();
		std::string getName();
		std::string getTitle();
		void polymorph(const Victim &) const;
	private:
		std::string _name;
		std::string _title;
};

std::ostream &operator<<(std::ostream &, Sorcerer &);

#endif /* !SORCERER_HPP_ */
