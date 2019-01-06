//
// EPITECH PROJECT, 2018
// piscine cpp
// File description:
// doctor
//

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string str)
{
	doc_name = str;
	std::cout << "Dr." << doc_name << ": I'm Dr." << doc_name
	<< "! How do you kreog?" << std::endl;
	in_job = false;
}

void	KoalaDoctor::diagnose(SickKoala *Jeanmi)
{
	std::string	report_name;
	std::string	drugs[5] = {"mars", "Buronzand", "Viagra",
					"Extasy", "Eucalyptus leaf"};
	std::string	temp = drugs[random() % 5];

	std::cout << "Dr." << doc_name
	<< " So what's goerking your Mr." << Jeanmi->getName()
	<< "!" << std::endl;
	Jeanmi->poke();
	report_name = Jeanmi->getName() + ".report";
	std::ofstream	report_file(report_name);
	if (report_file.is_open())
		report_file << temp;
}

void	KoalaDoctor::timeCheck()
{
	in_job = !in_job;
	if (in_job == true)
		std::cout << "Dr." << doc_name << ": Time to get to work!" << std::endl;
	else
		std::cout << "Dr." << doc_name << ": Time to go to my eucalyptus forest" << std::endl;
}

std::string KoalaDoctor::getName()
{
	return doc_name;
}