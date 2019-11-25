#include "Engine.h"
#include <iostream>

bool Engine::detectCollisions(Ball& ball, Obstacle& obstacle)
{
	
	if (ball.boundBox().intersects(obstacle.boundBox()))
	{

		obstacle.collide(ball);
	}
	return true;
}

