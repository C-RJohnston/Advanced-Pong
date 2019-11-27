#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(1600, 900), "Pinball", Style::Default);

	m_View.setSize(resolution);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.jpg");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::run()
{
	// Timing 	
	Clock clock;

	m_Ball.spawn(Vector2f(400, 500), Vector2f(0, 800), g, 1.0);
	m_Obstacles[0].spawn(Vector2f(400, 700), 1.0, 45);
	//m_Obstacles[1].spawn(Vector2f(600, 700), 1.0, 45);
	//m_Obstacles[2].spawn(Vector2f(600, 300), 1.0, 45*5);
	//m_Obstacles[3].spawn(Vector2f(400, 300), 1.0, 45 * 7);

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		// Update the total game time
		m_GameTimeTotal += dt;
		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}