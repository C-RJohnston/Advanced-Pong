#include "Engine.h"
float timeElapsed = 0;

void Engine::update(float dtAsSeconds)
{
	timeElapsed += dtAsSeconds;
	m_Ball.update(dtAsSeconds);

	for (int i = 0; i < 4; i++)
	{
		if (detectCollisions(m_Ball, m_Obstacles[i]))
		{

		}
	}
}