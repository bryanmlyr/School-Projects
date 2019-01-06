//
// EPITECH PROJECT, 2018
// piscine cpp
// File description:
// Koala classes
//

#ifndef SICKKOALA_HPP_
	#define SICKKOALA_HPP_

#include <iostream>
#include <string>
#include <regex>

class SickKoala {
	public:
		SickKoala(std::string);
		~SickKoala();
		void poke();
		bool takeDrug(std::string);
		void overDrive(std::string);
		std::string getName();
	private:
		std::string	koala_name;
};

#endif /* !SICKKOALA_HPP_ */
