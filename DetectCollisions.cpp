#include "Engine.h"
#include <iostream>

bool Engine::detectCollisions(Ball& ball, Obstacle& obstacle)
{
	
	if (ball.boundBox().intersects(obstacle.boundBox()))
	{

		m_Obstacle.collide(m_Ball);
	}
	return true;
}

