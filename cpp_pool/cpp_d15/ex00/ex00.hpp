/*
** EPITECH PROJECT, 2018
** ex00
** File description:
** Templates
*/

#ifndef EX00_HPP_
	#define EX00_HPP_

template <typename T>
void	swap(T &a, T &b)
{
	T tempA = a;
	T tempB = b;

	a = tempB;
	b = tempA;
}

template <typename T>
T	min(const T &a, const T &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T	max(const T &a, T &b)
{
	if (a > b)
		return a;
	else
		return b;
}

template <typename T>
T	add(const T &a, const T &b)
{
	return a + b;
}

#endif /* !EX00_HPP_ */