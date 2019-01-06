/*
** EPITECH PROJECT, 2018
** Find ex00
** File description:
** Template
*/

#ifndef FIND_HPP_
	#define FIND_HPP_

#include <algorithm>
#include <iterator>

template <typename T>
auto do_find(T &a, int b)
{
	return find(a.begin(), a.end(), b);
}

#endif /* !FIND_HPP_ */
