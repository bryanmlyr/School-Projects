/*
** EPITECH PROJECT, 2018
** Exercise 0
** File description:
** Toy
*/

#include "Picture.hpp"
#include <iostream>
#include <fstream>

Picture::Picture()
{
	data = "";
}

Picture::Picture(const std::string &path)
{
	getPictureFromFile(path);
}

Picture::~Picture()
{}

bool	Picture::getPictureFromFile(const std::string &path)
{
	std::ifstream	file(path);

	if (file.is_open()) {
		getline(file, data, '\0');
		return true;
	} else {
		data = "ERROR";
		return false;
	}
}