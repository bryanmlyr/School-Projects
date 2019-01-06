/*
** EPITECH PROJECT, 2018
** ex04
** File description:
** template class
*/

#include "ex04.hpp"
#include <string>

template <typename T>
bool Tester<T>::equal(T a, T b)
{
	if (a == b)
		return true;
	return false;
}

template bool Tester<int>::equal(int, int);
template bool Tester<float>::equal(float, float);
template bool Tester<double>::equal(double, double);
template bool Tester<std::string>::equal(std::string, std::string);

template <typename T>
bool	equal(T a, T b)
{
	if (a == b)
		return true;
	return false;
}

template bool equal(int, int);
template bool equal(float, float);
template bool equal(double, double);
template bool equal(std::string, std::string);