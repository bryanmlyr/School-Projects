/*
** EPITECH PROJECT, 2018
** ex02
** File description:
** template
*/

#ifndef EX02_HPP_
	#define EX02_HPP_

#include <iostream>

template <typename T>
T	min(T a, T b)
{
	std::cout << "template min" << std::endl;
	if (a == b)
		return a;
	if (a > b)
		return b;
	return a;
}

template <typename T>
T	templateMin(T *a, const int &b)
{
	int x = 1;
	int retMin = a[0];

	while (x != b) {
		retMin = ::min(retMin, a[x]);
		x++;
	}
	return retMin;
}

int	min(int a, int b)
{
	std::cout << "non-template min" << std::endl;
	if (a == b)
		return a;
	if (a > b)
		return b;
	return a;
}

int	nonTemplateMin(int *array, int size)
{
	int x = 1;
	int retMin = array[0];

	while (x != size) {
		retMin = min(retMin, array[x]);
		x++;
	}
	return retMin;
}

#endif /* !EX02_HPP_ */
