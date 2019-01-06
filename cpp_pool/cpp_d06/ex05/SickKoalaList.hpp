//
// EPITECH PROJECT, 2018
// piscine cpp
// File description:
// ex05
//

#ifndef SICKKOALALIST_HPP_
	#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class	SickKoalaList {
	public:
		SickKoalaList(SickKoala *);
		bool isEnd();
		void append(SickKoalaList *);
};

#endif /* !SICKKOALALIST_HPP_ */
