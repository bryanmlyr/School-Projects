/*
** EPITECH PROJECT, 2018
** Class Encryption
** File description:
** ex03
*/

#include "Encryption.hpp"
#include <iostream>

Encryption::Encryption(IEncryptionMethod &wow, void (IEncryptionMethod::*issou)(char temp))
: _meth(wow), _temp(issou)
{}

Encryption::~Encryption()
{}

Encryption &Encryption::operator()(char wow)
{
	(_meth.*_temp)(wow);
	return *this;
}

void Encryption::encryptString(IEncryptionMethod &meth, const std::string &str)
{
	meth.reset();
	std::for_each(str.begin(), str.end(), Encryption(meth, &IEncryptionMethod::encryptChar));
	std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &meth, const std::string &str)
{
	meth.reset();
	std::for_each(str.begin(), str.end(), Encryption(meth, &IEncryptionMethod::decryptChar));
	std::cout << std::endl;
}
