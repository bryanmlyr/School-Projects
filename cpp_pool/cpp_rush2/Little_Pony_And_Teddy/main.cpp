/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** main.cpp
*/

#include "littlepony.hpp"
#include "object.hpp"
#include "teddy.hpp"
#include "toy.hpp"

Object  **MyUnitTests()
{
        Object **all_objects = new Object *[2];
        all_objects[0] = new Teddy("cuddles");
        all_objects[1] = new LittlePony("happy pony");

	all_objects[0]->isTaken();
        all_objects[1]->isTaken();

	std::cout << "Teddy speak: " << std::endl;
	all_objects[0]->setTaken(true);
        all_objects[0]->isTaken();

	std::cout << "LittlePony speak: " << std::endl;
	all_objects[1]->setTaken(true);
        all_objects[1]->isTaken();

	std::cout << "Teddy title: " << all_objects[0]->getTitle() << std::endl;
        std::cout << "LitlePony title: " << all_objects[1]->getTitle()
		<< std::endl;
        return all_objects;
}

int     main()
{
        MyUnitTests();
        return 0;
}
