#include "Engine.h"

void Engine::draw()
{
	//erase the previous frame
	m_Window.clear(Color::White);

	//draw the background
	m_Window.setView(m_BGView);
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Ball.getCircle());
	for (int i = 0; i < 4; i++)
	{
		m_Window.draw(m_Obstacles[i].getRect());
	}


	m_Window.setView(m_HudView);

	m_Window.display();
}