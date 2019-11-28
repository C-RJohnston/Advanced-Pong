#include "Engine.h"
#include <iostream>
#include "Maths.h"

float Max=-INFINITY;
Vector2f corner;
float proj;

bool Engine::detectCollisions(Ball& ball, Obstacle& obstacle)
{
	Vector2f displacement = ball.getCenter()-obstacle.getCenter();
	Vector2f nDisplacement = normal(displacement);
	for (int i = 0; i < obstacle.getRect().getPointCount(); i++)
	{
		corner = obstacle.getCorners(i);
		proj = dot(nDisplacement, corner);
		std::cout << i;
		printVect(corner);
		if (Max < proj)
		{
			Max = proj;
		}
	}
	if (sqrt(dot(displacement, displacement)) - Max - ball.getCircle().getRadius() > 0 && sqrt(dot(displacement, displacement)) > 0)
	{
		obstacle.collide(ball);
	}
	


	return true;
}

