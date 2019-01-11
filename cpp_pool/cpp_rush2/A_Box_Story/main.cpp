/*
** EPITECH PROJECT, 2018
** A Box Story
** File description:
** MyUnitTests
*/

#include "Box.hpp"
#include "GiftPaper.hpp"
#include "teddy.hpp"

Object	*MyUnitTests(Object **objs)
{
	objs[1]->wrapMeThat(objs[0]);

	objs[1]->openMe();
	objs[1]->wrapMeThat(objs[0]);
	objs[1]->wrapMeThat(objs[0]);

	objs[1]->removeObject();
	objs[1]->closeMe();
	objs[1]->wrapMeThat(objs[0]);
	objs[1]->openMe();
	objs[1]->wrapMeThat(objs[0]);
	std::cout << objs[0]->getTitle() << std::endl;
	objs[2]->wrapMeThat(objs[1]);
	return (objs[2]);
}

int	main()
{
	Object **objs = new Object *[3];

	objs[0] = new Teddy("Sponible");
	objs[1] = new Box();
	objs[2] = new GiftPaper();
	MyUnitTests(objs);
	return 0;
}