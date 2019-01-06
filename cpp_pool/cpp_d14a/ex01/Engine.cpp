
#include <cmath>
#include <string>
#include "Errors.hpp"
#include "Engine.hpp"
#include <iostream>

#define POW_2(x) (x * x)
#define ABS(x) (x < 0 ? -x : x)

Engine::Engine(float power, float x, float y)
    : _power(power),
      _x(x),
      _y(y)
{
}

Engine::~Engine()
{
}

void Engine::goTorward(float x, float y)
{
	std::string str = "Cannot reach destination (" + std::to_string((int)x) + ", " + std::to_string((int)y) + ").";
	if (ABS(x) > 2 && ABS(y) > 2)
		throw UserError(str, "Engine");
    _x = x;
    _y = y;
}

float Engine::distanceTo(float x, float y) const
{
    return std::sqrt(POW_2(ABS(x - _x)) + POW_2(ABS(y - _y)));
}

float Engine::getX() const
{
    return _x;
}

float Engine::getY() const
{
    return _y;
}

