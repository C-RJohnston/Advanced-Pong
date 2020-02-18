#include "Engine.h"
#include <iostream>
#include <string>
float timeElapsed = 0;

void Engine::update(float dtAsSeconds)
{
	timeElapsed += dtAsSeconds;
	m_Ball.update(dtAsSeconds);
	m_P1.update(dtAsSeconds);
	m_P2.update(dtAsSeconds);

		if (detectCollisions(m_Ball, m_P1))
		{
			m_hitSound.play();
		}
		if (detectCollisions(m_Ball, m_P2))
		{
			m_hitSound.play();
		}

		if (m_Ball.getPosition().x >= 1550)
		{
			m_P1.scoreUp();
			m_1ScoreText.setString(std::to_string(m_P1.getScore()));
			m_Ball.reset(1);
		}
		else if (m_Ball.getPosition().x <= -500)
		{
			m_P2.scoreUp();
			m_2ScoreText.setString(std::to_string(m_P2.getScore()));
			m_Ball.reset(-1);
		}
}