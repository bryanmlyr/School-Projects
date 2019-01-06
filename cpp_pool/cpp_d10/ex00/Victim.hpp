/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** victim
*/

#ifndef VICTIM_HPP_
	#define VICTIM_HPP_

#include <string>
#include <iostream>

class Victim {
	public:
		Victim(const std::string &);
		~Victim();
		std::string getName();
		virtual void getPolymorphed() const;
	protected:
		std::string	_name;
};

std::ostream	&operator<<(std::ostream &, Victim &);

#endif /* !VICTIM_HPP_ */
