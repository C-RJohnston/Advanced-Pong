#include "Engine.h"
#include <iostream>
float timeElapsed = 0;
bool boinked = false;

void Engine::update(float dtAsSeconds)
{
	timeElapsed += dtAsSeconds;
	m_Ball.update(dtAsSeconds);
	for (int i = 0; i < 4; i++)
	{

			if (detectCollisions(m_Ball, m_Obstacles[i]))
			{
// 				m_Obstacles[i].collide(m_Ball);
// 				boinked = true;
// 				std::cout << "collision" << '\n';
			}

	}
}