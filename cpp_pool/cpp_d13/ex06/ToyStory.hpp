/*
** EPITECH PROJECT, 2018
** Exercise 6
** File description:
** Toy Story
*/

#ifndef TOYSTORY_HPP_
	#define TOYSTORY_HPP_

#include "Toy.hpp"
#include <fstream>

class ToyStory {
	public:
		static void	tellMeAStory(const std::string &path, Toy toy1, bool (Toy::* func1)(const std::string &), Toy toy2, void (Toy::* func2)(const std::string &)) {
			std::string 	input;
			std::ifstream	file(path);
			int		x = 0;

			std::cout << toy1.getAscii() << std::endl;
			std::cout << toy2.getAscii() << std::endl;
			while (getline(file, input, '\n')) {
				if (x % 2 == 0) {
					if (input.compare(0, 8,"picture:") == 0) {
						toy1.setAscii(input.substr(8, input.length() - 8));
						std::cout << toy1.getAscii() << std::endl;
					} else {
						(toy1.*func1)(input);
					}
				} else {
					if (input.compare(0, 8,"picture:") == 0) {
						toy2.setAscii(input.substr(8, input.length() - 8));
						std::cout << toy1.getAscii() << std::endl;
					} else {
						(toy2.*func2)(input);
					}
				}
				x++;
			}
		}
};

#endif /* !TOYSTORY_HPP_ */
