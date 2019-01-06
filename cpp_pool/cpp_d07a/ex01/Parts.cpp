/*
** EPITECH PROJECT, 2018
** piscine
** File description:
** jour7
*/

#include "Parts.hpp"

Arms::Arms() {
	_serial = "A-01";
	_functionnal = true;
}

Arms::Arms(std::string &str) {
	_serial = str;
	_functionnal = true;
}

Arms::Arms(std::string &str, bool func) {
	_serial = str;
	_functionnal = func;
}

bool Arms::isFunctionnal() {
	return _functionnal;
}

std::string Arms::serial() {
	return _serial;
}

void Arms::informations() {
	std::cout << "\t [Parts] Arms " << _serial << " : ";
	if (_functionnal)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}

Legs::Legs() {
	_serial = "L-01";
	_functionnal = true;
}

Legs::Legs(std::string &str) {
	_serial = str;
	_functionnal = true;
}

Legs::Legs(std::string &str, bool func) {
	_serial = str;
	_functionnal = func;
}

bool Legs::isFunctionnal() {
	return _functionnal;
}

std::string Legs::serial() {
	return _serial;
}

void Legs::informations() {
	std::cout << "\t [Parts] Legs " << _serial << " : ";
	if (_functionnal)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}

Head::Head() {
	_serial = "H-01";
	_functionnal = true;
}

Head::Head(std::string &str) {
	_serial = str;
	_functionnal = true;
}

Head::Head(std::string &str, bool func) {
	_serial = str;
	_functionnal = func;
}

bool Head::isFunctionnal() {
	return _functionnal;
}

std::string Head::serial() {
	return _serial;
}

void Head::informations() {
	std::cout << "\t [Parts] Head " << _serial << " : ";
	if (_functionnal)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}