#include "Engine.h"

void Engine::draw()
{
	//erase the previous frame
	m_Window.clear(Color::White);

	//draw the background
	m_Window.setView(m_BGView);
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Ball.getCircle());
	m_Window.draw(m_Obstacle.getRect());
	m_Window.draw(m_Obstacle2.getRect());


	m_Window.setView(m_HudView);

	m_Window.display();
}