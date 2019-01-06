/*
** EPITECH PROJECT, 2018
** ex03
** File description:
** template
*/

#ifndef EX03_HPP_
	#define EX03_HPP_

#include <iostream>

template <typename T>
void	print(const T &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void	foreach(T *a, void (*func)(const T &elem), int size)
{
	for (int x = 0; x != size; x++)
		(func)(a[x]);
}

#endif /* !EX03_HPP_ */
