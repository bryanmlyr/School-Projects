/*
** EPITECH PROJECT, 2018
** Ratatouille
** File description:
** Ex04
*/

#ifndef RATATOUILLE_HPP_
	#define RATATOUILLE_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Ratatouille {
	public:
		Ratatouille();
		virtual ~Ratatouille();
		Ratatouille &operator=(const Ratatouille &);
		Ratatouille &addVegetable(unsigned char);
		Ratatouille &addCondiment(unsigned int);
		Ratatouille &addSpice(double);
		Ratatouille &addSauce(const std::string &);
		std::string kooc();
	private:
		std::vector<std::string>	_str;
};

#endif /* !RATATOUILLE_HPP_ */
