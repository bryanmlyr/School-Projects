/*
** EPITECH PROJECT, 2018
** Exercise 2
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name) : Toy(WOODY, name, "./woody.txt")
{
}

Woody::Woody(const std::string &name, const std::string &path) : Toy(WOODY, name, path)
{
}

Woody::~Woody()
{
}
