#include "Engine.h"

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
	m_Ball.spawn(Vector2f(400, 500), Vector2f(0, -800), g, 0.7);
	m_Obstacle.spawn(Vector2f(400, 900), 0.5);

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