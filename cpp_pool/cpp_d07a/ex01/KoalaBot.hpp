/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** koala bot
*/

#ifndef KOALABOT_HPP_
	#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot {
	public:
		KoalaBot();
		void setParts(Arms &);
		void setParts(Legs &);
		void setParts(Head &);
		void swapParts(Arms &, Arms &);
		void swapParts(Legs &, Legs &);
		void swapParts(Head &, Head &);
		void informations();
		bool status();
		Arms a1;
		Legs l1;
		Head h1;
	private:
		std::string _serial;
};

#endif /* !KOALABOT_HPP_ */
