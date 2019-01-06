/*
** EPITECH PROJECT, 2018
** jour 7aprem
** File description:
** ex00
*/

#ifndef SKAT_HPP_
	#define SKAT_HPP_

#include <string>

class Skat {
	public:
		Skat();
		Skat(const std::string &);
		Skat(const std::string &, int);
		int 			&stimPaks();
		const std::string	&name();
		void 			shareStimPaks(int, int &);
		void			addStimPaks(unsigned int);
		void			useStimPaks();
		void			status();

	private:
		std::string		wow;
		int			nb;
};

#endif /* !SKAT_HPP_ */
