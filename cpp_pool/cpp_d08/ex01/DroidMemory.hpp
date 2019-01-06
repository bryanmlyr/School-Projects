/*
** EPITECH PROJECT, 2018
** piscine cpp
** File description:
** ex01
*/

#ifndef DROIDMEMORY_HPP_
	#define DROIDMEMORY_HPP_

#include <string>

class	DroidMemory {
	public:
		DroidMemory();
		size_t	getFingerPrint();
		void	setFingerPrint(size_t);
		size_t	getExp();
		void	setExp(size_t);
		void	operator<<(const DroidMemory &);
		void	operator>>(DroidMemory &);
		void	operator+=(size_t);
		DroidMemory operator+(size_t);
		void	operator+(const DroidMemory);
	private:
		size_t	FingerPrint;
		size_t	Exp;
};

std::ostream	&operator<<(std::ostream &, DroidMemory);

#endif /* !DROIDMEMORY_HPP_ */
