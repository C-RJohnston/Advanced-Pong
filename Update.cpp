#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
	m_Ball.update(dtAsSeconds);

	detectCollisions(m_Ball, m_Obstacle);
}