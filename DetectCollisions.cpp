#include "Engine.h"
#include <iostream>



bool Engine::detectCollisions(Ball& ball, Obstacle& obstacle)
{
	Vector2f lines = obstacle.getLines();
	std::cout << lines.x << '\n';

	return true;
}

