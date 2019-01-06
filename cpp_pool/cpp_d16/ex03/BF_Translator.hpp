/*
** EPITECH PROJECT, 2018
** BrainFuck
** File description:
** class
*/

#ifndef BF_TRANSLATOR_HPP_
	#define BF_TRANSLATOR_HPP_

#include <string>

class BF_Translator {
	public:
		BF_Translator();
		virtual ~BF_Translator();
		int translate(const std::string &, const std::string &);
};

#endif /* !BF_TRANSLATOR_HPP_ */
