#include "Player1.h"

Player1::Player1()
{
	m_Rect.setSize(Vector2f(200, 30));
	m_RotVel = 60;
	m_Score = 0;
}

void Player1::handleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		m_upPressed = true;
	}
	else
	{
		m_upPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		m_downPressed = true;
	}
	else
	{
		m_downPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_leftPressed = true;
	}
	else
	{
		m_leftPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_rightPressed = true;
	}
	else
	{
		m_rightPressed = false;
	}

}


