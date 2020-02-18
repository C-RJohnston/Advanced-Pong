#include "Engine.h"
#include "Maths.h"

void Engine::draw()
{
	//erase the previous frame
	m_Window.clear(Color::White);

	//draw the background
	m_Window.setView(m_BGView);
	m_Window.draw(m_BackgroundSprite);
	m_Window.setView(m_View);
	m_Window.draw(m_Ball.getCircle());
	m_Window.draw(m_P1.getRect());
	m_Window.draw(m_P2.getRect());



	m_Window.setView(m_HudView);
	m_Window.draw(m_1ScoreText);
	m_Window.draw(m_2ScoreText);
	m_Window.draw(m_DividerText);


	m_Window.display();
}