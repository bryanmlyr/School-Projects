/*
** EPITECH PROJECT, 2018
** Exercise 2
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
	#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
	public:
		Buzz(const std::string &);
		Buzz(const std::string &, const std::string &);
		void speak(const std::string &);
		bool speak_es(const std::string &);
		~Buzz();
};

#endif /* !BUZZ_HPP_ */
