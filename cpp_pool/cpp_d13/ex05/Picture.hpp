/*
** EPITECH PROJECT, 2018
** Exercise 0
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
	#define PICTURE_HPP_

#include <string>

class Picture {
	public:
		Picture();
		Picture(const std::string &file);
		~Picture();
		const Picture	&operator=(const Picture &);
		bool		getPictureFromFile(const std::string &file);
		std::string	data;
};

#endif /* !PICTURE_HPP_ */
