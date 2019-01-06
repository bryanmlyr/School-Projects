/*
** EPITECH PROJECT, 2018
** Exercise 0
** File description:
** Toy
*/

#ifndef TOY_HPP_
	#define TOY_HPP_

#include "Picture.hpp"


class Toy {
	public:
		enum ToyType{BASIC_TOY, ALIEN, BUZZ, WOODY};
		Toy();
		Toy(ToyType, const std::string &, const std::string &);
		~Toy();
		Toy::ToyType	getType() const;
		std::string	getName() const;
		void		setName(const std::string &);
		bool		setAscii(const std::string &);
		std::string	getAscii() const;
		const Toy	&operator=(const Toy &);
	protected:
		Picture		_picture;
		Toy::ToyType	_type;
		std::string	_toyName;
};

#endif /* !TOY_HPP_ */
