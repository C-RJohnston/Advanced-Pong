#include "Paddle.h"
#include "Maths.h"


void Paddle::update(float timeElapsed)
{
	if (m_upPressed)
	{
		m_Position -= m_Velocity * timeElapsed;
		setPosition(m_Position);
	};

	if (m_downPressed)
	{
		m_Position += m_Velocity * timeElapsed;
		setPosition(m_Position);
	};

	if (m_leftPressed)
	{
		m_Angle -= m_RotVel * timeElapsed;
		setAngle(m_Angle);

	};

	if (m_rightPressed)
	{
		m_Angle += m_RotVel * timeElapsed;
		setAngle(m_Angle);

	};


};

int Paddle::getScore()
{
	return m_Score;
}

void Paddle::setScore(int score)
{
	m_Score = score;
}

void Paddle::scoreUp()
{
	m_Score++;
}
