/*
** EPITECH PROJECT, 2018
** rush02
** File description:
** LittlePony and Teddy
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>
#include <iostream>

class	Object
{
	public:
		Object(const std::string &);
		~Object();
		virtual void isTaken();
		std::string getTitle() const;
		void setTaken(bool status);
	protected:
		std::string	_title;
		bool		_taken;
};

#endif /* !OBJECT_HPP_ */
