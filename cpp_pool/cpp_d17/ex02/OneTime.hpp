/*
** EPITECH PROJECT, 2018
** OneTime
** File description:
** ex02
*/

#ifndef ONETIME_HPP_
	#define ONETIME_HPP_

#include <string>
#include <iostream>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod {
	public:
		OneTime(const std::string &);
		virtual ~OneTime();
		void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset();
		int toInt(char c);
	private:
		std::string		_key;
		unsigned int		_posKey;
};

#endif /* !ONETIME_HPP_ */
