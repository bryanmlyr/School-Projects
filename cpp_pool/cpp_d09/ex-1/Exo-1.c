/*
** EPITECH PROJECT, 2018
** ex01
** File description:
** ex-01
*/

#include "Exo-1.h"
#include <stdlib.h>
#include <stdio.h>

static void	CthulhuInitializer(cthulhu_t *this)
{
	this->m_name = "Cthulhu";
	this->m_power = 42;
	printf("----\nBuilding Cthulhu\n");
}

cthulhu_t	*NewCthulhu()
{
	cthulhu_t	*new = malloc(sizeof(cthulhu_t));
	if (new == NULL)
		return (NULL);

	CthulhuInitializer(new);
	return (new);
}

void	PrintPower(cthulhu_t *this)
{
	printf("Power => %d\n", this->m_power);
}

void	Attack(cthulhu_t *this)
{
	if (this->m_power >= 42) {
		this->m_power -= 42;
		printf("%s attacks and destroys the city\n", this->m_name);
	} else {
		printf("%s can't attack, he doesn't have enough power\n", this->m_name);
	}
}

void	Sleeping(cthulhu_t *this)
{
	printf("%s sleeps\n", this->m_name);
	this->m_power += 42000;
}

static void KoalaInitializer(koala_t *this, char *_name, char _isALegend)
{
	printf("Building Cthulhu\n");
	printf("Building %s\n", _name);
	this->m_parent.m_name = _name;
	if (_isALegend == 1)
		this->m_parent.m_power = 42;
	else
		this->m_parent.m_power = 0;
	this->m_isALegend = _isALegend;
}

koala_t	*NewKoala(char *name, char _isALegend)
{
	koala_t	*new = malloc(sizeof(koala_t));
	if (new == NULL)
		return (NULL);

	KoalaInitializer(new, name, _isALegend);
	return (new);
}

void	Eat(koala_t *this)
{
	printf("%s eats\n", this->m_parent.m_name);
	this->m_parent.m_power += 42;
}