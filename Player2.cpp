#include "Player2.h"

Player2::Player2()
{
	m_Rect.setSize(Vector2f(200, 30));
	m_RotVel = 60;
	m_Score = 0;
}

void Player2::handleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		m_upPressed = true;
	}
	else
	{
		m_upPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		m_downPressed = true;
	}
	else
	{
		m_downPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_leftPressed = true;
	}
	else
	{
		m_leftPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_rightPressed = true;
	}
	else
	{
		m_rightPressed = false;
	}

}



