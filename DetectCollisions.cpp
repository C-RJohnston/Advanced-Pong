#include "Engine.h"
#include <iostream>
#include "Maths.h"



bool Engine::detectCollisions(Ball& ball, Obstacle& obstacle)
{

	Vector2f local = rotate(ball.getPosition(), -obstacle.getAngle(), obstacle.getCenter());

	Vector2f delta = Vector2f(
		local.x -
		std::max(obstacle.getPosition().x - obstacle.getRect().getSize().x/2,
			std::min(local.x, obstacle.getPosition().x + obstacle.getRect().getSize().x/2)),
		local.y -
		std::max(obstacle.getPosition().y - obstacle.getRect().getSize().y/2,
			std::min(local.y, obstacle.getPosition().y + obstacle.getRect().getSize().y/2))
	);




	if (dot(delta, delta) < pow(ball.getCircle().getRadius(),2))
	{
		obstacle.collide(ball);
		return true;
	}


	return false;
}

