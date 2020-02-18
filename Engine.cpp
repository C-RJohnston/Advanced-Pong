#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(1600,900), "Pinball", Style::Default);

	m_Font.loadFromFile("ManilaSansBld.otf");
	m_1ScoreText.setFont(m_Font);
	m_2ScoreText.setFont(m_Font);
	m_DividerText.setFont(m_Font);
	m_1ScoreText.setFillColor(Color::White);
	m_2ScoreText.setFillColor(Color::White);
	m_DividerText.setFillColor(Color::White);
	m_1ScoreText.setCharacterSize(150);
	m_2ScoreText.setCharacterSize(150);
	m_DividerText.setCharacterSize(150);
	m_1ScoreText.setString("0");
	m_2ScoreText.setString("0");
	m_DividerText.setString("|");
	m_1ScoreText.setPosition(950, 0);
	m_DividerText.setPosition(850, 0);
	m_2ScoreText.setPosition(750, 0);
	
	m_hitBuffer.loadFromFile("Sounds/hit.wav");
	m_scoreBuffer.loadFromFile("Sounds/score.wav");

	m_hitSound.setBuffer(m_hitBuffer);
	m_scoreSound.setBuffer(m_scoreBuffer);

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.jpg");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	m_View.setSize(resolution);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));


}

void Engine::run()
{
	// Timing 	
	Clock clock;

	m_P1.spawn(Vector2f(1400, 300), 0.9f, 90, Vector2f(0, 200));
	m_P2.spawn(Vector2f(-400, 300), 0.9f, 90, Vector2f(0, 200));
	m_Ball.spawn(Vector2f(400, 300), Vector2f(300, 0), Vector2f(0,0), 0.9f);

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