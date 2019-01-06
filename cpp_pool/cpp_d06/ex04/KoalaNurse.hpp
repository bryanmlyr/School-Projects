//
// EPITECH PROJECT, 2018
// cpp pool
// File description:
// ex03 nurse
//

#ifndef NURSEKOALA_HPP_
	#define NURSEKOALA_HPP_

#include <string>
#include <fstream>
#include "SickKoala.hpp"

class KoalaNurse {
	public:
		KoalaNurse(int);
		~KoalaNurse();
		void giveDrug(std::string, SickKoala *);
		std::string readReport(std::string);
		void timeCheck();
	private:
		int	id;
		bool	in_job;
};

#endif /* !NURSEKOALA_HPP_ */
