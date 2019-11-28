#include "Engine.h"

void Engine::draw()
{
	//erase the previous frame
	m_Window.clear(Color::White);

	//draw the background
	m_Window.setView(m_BGView);
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Ball.getCircle());
	for (int i = 0; i < 1; i++)
	{
		m_Window.draw(m_Obstacles[i].getRect());
	}
	CircleShape circle1(5.0, 30);
	circle1.setPosition(m_Obstacles[0].getCorners(0));
	circle1.setFillColor(sf::Color::Blue);
	circle1.setOrigin(2.5, 2.5);
	m_Window.draw(circle1);
	CircleShape circle2(5.0, 30);
	circle2.setPosition(m_Obstacles[0].getCorners(1));
	circle2.setFillColor(sf::Color::Green);
	circle2.setOrigin(2.5, 2.5);
	m_Window.draw(circle2);
	CircleShape circle3(5.0, 30);
	circle3.setPosition(m_Obstacles[0].getCorners(2));
	circle3.setFillColor(sf::Color::Red);
	circle3.setOrigin(2.5, 2.5);
	m_Window.draw(circle3);
	CircleShape circle4(5.0, 30);
	circle4.setPosition(m_Obstacles[0].getCorners(3));
	circle4.setFillColor(sf::Color::Magenta);
	circle4.setOrigin(2.5, 2.5);
	m_Window.draw(circle4);

	m_Window.setView(m_HudView);

	m_Window.display();
}