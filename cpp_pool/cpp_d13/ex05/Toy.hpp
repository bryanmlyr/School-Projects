/*
** EPITECH PROJECT, 2018
** Exercise 0
** File description:
** Toy
*/

#ifndef TOY_HPP_
	#define TOY_HPP_

#include "Picture.hpp"
#include <iostream>

class Toy {
	public:
		enum ToyType{BASIC_TOY, ALIEN, BUZZ, WOODY};
		Toy();
		Toy(ToyType, const std::string &, const std::string &);
		~Toy();
		Toy::ToyType	getType() const;
		std::string	getName();
		void		setName(const std::string &);
		bool		setAscii(const std::string &);
		std::string	getAscii();
		virtual	bool	speak_es(const std::string &);
		virtual void	speak(const std::string &);
		const Toy	&operator=(const Toy &);
		Toy		&operator<<(const std::string &);
		enum		LastError{UNKNOWN, PICTURE, SPEAK};

		class Error {
			public:
				Error(Toy::LastError);
				enum		ErrorType{UNKNOWN, PICTURE, SPEAK};
				std::string 	what() const;
				std::string 	where() const;
				ErrorType	type;
		};

		Toy::Error	getLastError();
	protected:
		Picture		_picture;
		Toy::ToyType	_type;
		std::string	_toyName;
		LastError	_last = UNKNOWN;
};

std::ostream	&operator<<(std::ostream &, Toy &);

#endif /* !TOY_HPP_ */
