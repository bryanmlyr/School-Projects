//
// EPITECH PROJECT, 2018
// piscine
// File description:
// ex04
//

#ifndef KOALADOCTOR_HPP_
	#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"

class KoalaDoctor {
	public:
		KoalaDoctor(std::string);
		void diagnose(SickKoala *);
		void timeCheck();
		std::string getName();
	private:
		std::string doc_name;
		bool in_job;
};

#endif /* !KOALADOCTOR_HPP_ */
