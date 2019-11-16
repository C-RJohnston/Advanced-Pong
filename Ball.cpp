#include "Ball.h"
#include "TextureHolder.h"
#include <iostream>

Ball::Ball()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/ball.png"));
}

void Ball::spawn(Vector2f startPosition, Vector2f startVelocity, Vector2f gravity)
{

	m_Position = startPosition;
	m_Velocity = startVelocity;

	m_Gravity = gravity;

	m_Sprite.setPosition(m_Position);
}

void Ball::update(float elapsedTime)
{
	m_Velocity += m_Gravity * elapsedTime;
	m_Position += m_Velocity * elapsedTime;
	std::cout << m_Velocity.y << '\n';


	m_Sprite.setPosition(m_Position);
}

FloatRect Ball::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Ball::getCenter()
{
	return Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width / 2, m_Position.y + m_Sprite.getGlobalBounds().height / 2);
}

Sprite Ball::getSprite()
{
	return m_Sprite;
}