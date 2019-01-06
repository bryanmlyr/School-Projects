/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** peon
*/

#ifndef PEON_HPP_
	#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim {
	public:
		Peon(const std::string &);
		~Peon();
		void getPolymorphed() const;
};

#endif /* !PEON_HPP_ */
