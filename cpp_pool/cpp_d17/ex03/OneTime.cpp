/*
** EPITECH PROJECT, 2018
** OneTime
** File description:
** ex02
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key)
{
	_key = key;
	_posKey = 0;
}

OneTime::~OneTime()
{
}

int	OneTime::toInt(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else
		return c - 'a';
}

void	OneTime::encryptChar(char plainchar)
{
	char temp;

	if (_posKey == _key.size())
		_posKey = 0;
	if (plainchar >= 'A' && plainchar <= 'Z') {
		temp = 'A' + ((plainchar - 65) + toInt(_key[_posKey])) % 26;
		std::cout << temp;
	} else if (plainchar >= 'a' && plainchar <= 'z') {
		temp = 'a' + ((plainchar - 97) + toInt(_key[_posKey])) % 26;
		std::cout << temp;
	} else {
		std::cout << plainchar;
	}
	_posKey++;
}

void	OneTime::decryptChar(char cipherchar)
{
	char temp;

	if (_posKey == _key.size())
		_posKey = 0;
	if (cipherchar >= 'A' && cipherchar <= 'Z') {
		temp = 'Z' + ((cipherchar - 90) - toInt(_key[_posKey])) % 26;
		std::cout << temp;
	} else if (cipherchar >= 'a' && cipherchar <= 'z') {
		temp = 'z' + ((cipherchar - 122) - toInt(_key[_posKey])) % 26;
		std::cout << temp;
	} else {
		std::cout << cipherchar;
	}
	_posKey++;
}

void	OneTime::reset()
{
	_posKey = 0;
}
