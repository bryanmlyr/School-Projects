//
// EPITECH PROJECT, 2018
// piscine cpp
// File description:
// KoalaNurse
//

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int iden) : id(iden), in_job(false)
{
}

KoalaNurse::~KoalaNurse()
{
	std::cout << "Nurse " << id << ": Finally some rest!" << std::endl;
}

void	KoalaNurse::giveDrug(std::string str, SickKoala *Jeanmi)
{
	Jeanmi->takeDrug(str);
}

std::string	KoalaNurse::readReport(std::string str)
{
	std::string	out;
	std::string	drug_name = "";
	std::ifstream	file(str);

	if (!file.is_open())
		return drug_name;
	std::getline(file, drug_name, '\0');
	out = str.substr(0, str.find(".report"));
	std::cout << "Nurse " << id << ": Kreog! Mr." << out << " needs a "
	<< drug_name << "!" << std::endl;
	return drug_name;
}

void	KoalaNurse::timeCheck()
{
	in_job = !in_job;
	if (in_job == true)
		std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
	else
		std::cout << "Nurse " << id << ": Time to go home to my eucalyptus forest!" << std::endl;
}