/*
** EPITECH PROJECT, 2018
** koalabot
** File description:
** exercise
*/

#ifndef PARTS_HPP_
	#define PARTS_HPP_

#include <string>
#include <iostream>

class Arms {
	public:
		Arms();
		Arms(std::string &);
		Arms(std::string &, bool);
		bool isFunctionnal();
		std::string serial();
		void informations();
	private:
		std::string	_serial;
		bool		_functionnal;
};

class Legs {
	public:
		Legs();
		Legs(std::string &);
		Legs(std::string &, bool);
		bool isFunctionnal();
		std::string serial();
		void informations();
	private:
		std::string	_serial;
		bool		_functionnal;
};

class Head {
	public:
		Head();
		Head(std::string &);
		Head(std::string &, bool);
		bool isFunctionnal();
		std::string serial();
		void informations();
	private:
		std::string	_serial;
		bool		_functionnal;
};

#endif /* !PARTS_HPP_ */
