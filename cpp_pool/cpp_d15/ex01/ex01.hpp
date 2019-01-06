/*
** EPITECH PROJECT, 2018
** ex01
** File description:
** compare
*/

#ifndef EX01_HPP_
	#define EX01_HPP_

template <typename T>
int	compare(const T &a, const T &b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	return 1;
}

template<>
int compare<const char *>(const char * const &a, const char * const &b) {
	if (a - b == 0)
		return 0;
	if (a - b < 0)
		return -1;
	return 1;
}

#endif /* !EX01_HPP_ */
