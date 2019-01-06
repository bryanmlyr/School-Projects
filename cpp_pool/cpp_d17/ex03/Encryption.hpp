/*
** EPITECH PROJECT, 2018
** Encryption
** File description:
** ex03
*/

#ifndef ENCRYPTION_HPP_
	#define ENCRYPTION_HPP_

#include <string>
#include <algorithm>
#include "IEncryptionMethod.hpp"

class Encryption {
	public:
		Encryption(IEncryptionMethod &, void (IEncryptionMethod::*)(char));
		Encryption &operator()(char);
		virtual ~Encryption();
		static void encryptString(IEncryptionMethod &, const std::string &);
		static void decryptString(IEncryptionMethod &, const std::string &);
	private:
		IEncryptionMethod &_meth;
		void (IEncryptionMethod::*_temp)(char);
};

#endif /* !ENCRYPTION_HPP_ */
