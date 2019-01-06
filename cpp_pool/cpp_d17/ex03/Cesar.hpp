/*
** EPITECH PROJECT, 2018
** Cesar
** File description:
** class
*/

#ifndef CESAR_HPP_
	#define CESAR_HPP_

#include <string>
#include <iostream>
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
	public:
		Cesar();
		virtual ~Cesar();
		void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset();
	private:
		int	retValueEnc = 3;
		int	retValueDec = 3;
};

#endif /* !CESAR_HPP_ */
