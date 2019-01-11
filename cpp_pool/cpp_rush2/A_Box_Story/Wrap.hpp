/*
** EPITECH PROJECT, 2018
** A box story
** File description:
** Warp
*/

#ifndef WRAP_HPP_
	#define WRAP_HPP_

#include "object.hpp"

class Wrap : public Object
{
	public:
		Wrap();
		~Wrap();
		virtual void wrapMeThat();
		void openMe();
		void closeMe();
		bool isOpen() const;
		void removeObject();
	protected:
		bool 	_Opened;
		Object *_Obj;
};

#endif /* !WRAP_HPP_ */
