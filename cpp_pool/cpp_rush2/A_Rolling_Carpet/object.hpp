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
		Object();
		Object(const std::string &);
		~Object();
		virtual void isTaken();
		virtual void wrapMeThat(Object *);
		virtual void openMe();
		virtual void closeMe();
		virtual bool isOpen() const;
		virtual void removeObject();
		std::string getTitle() const;
		void setTaken(bool status);
	protected:
		std::string	_title;
		bool		_taken;
};

#endif /* !OBJECT_HPP_ */
