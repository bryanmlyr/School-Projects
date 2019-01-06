/*
** EPITECH PROJECT, 2018
** Cesar
** File description:
** source
*/

#include "Cesar.hpp"

Cesar::Cesar()
{}

Cesar::~Cesar()
{}

void Cesar::encryptChar(char plainchar)
{
	char temp;

	if (plainchar >= 'A' && plainchar <= 'Z') {
		temp = 'A' + ((plainchar - 65) + retValueEnc) % 26;
		std::cout << temp;
	} else if (plainchar >= 'a' && plainchar <= 'z') {
		temp = 'a' + ((plainchar - 97) + retValueEnc) % 26;
		std::cout << temp;
	} else {
		std::cout << plainchar;
	}
	retValueEnc++;
}

void	Cesar::decryptChar(char cipherchar)
{
	char temp;

	if (cipherchar >= 'A' && cipherchar <= 'Z') {
		temp = 'Z' + ((cipherchar - 90) - retValueDec) % 26;
		std::cout << temp;
	} else if (cipherchar >= 'a' && cipherchar <= 'z') {
		temp = 'z' + ((cipherchar - 122) - retValueDec) % 26;
		std::cout << temp;
	} else {
		std::cout << cipherchar;
	}
	retValueDec++;
}

void	Cesar::reset()
{
	retValueEnc = 3;
	retValueDec = 3;
}