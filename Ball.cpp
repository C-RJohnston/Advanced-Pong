#include "Ball.h"
#include "TextureHolder.h"
#include <iostream>

Ball::Ball()
{
	m_Circle.setRadius(10);
	m_Circle.setFillColor(sf::Color::White);
}

void Ball::spawn(Vector2f startPosition, Vector2f startVelocity, Vector2f gravity, float restitution)
{

	m_Position = startPosition;
	START_POSITION = startPosition;
	m_Velocity = startVelocity;
	START_VELOCITY = startVelocity;

	m_Gravity = gravity;

	m_Restitution = restitution;
	m_Circle.setOrigin(Vector2f(5,5));
	m_Circle.setPosition(m_Position);

	
}

FloatRect Ball::boundBox()
{
	return m_Circle.getGlobalBounds();
}

void Ball::update(float elapsedTime)
{

	if (m_Position.y >= 900)
	{
		m_Velocity.y *= -1;
		m_Position.y = 900 - m_Circle.getRadius() * 2;
	}
	else if (m_Position.y < 0)
	{
		m_Velocity.y *= -1;
		m_Position.y = m_Circle.getRadius() * 2;
	}

	m_Velocity += m_Gravity * elapsedTime;
	m_Position += m_Velocity * elapsedTime;
	m_Circle.setPosition(m_Position);
}

 Vector2f Ball::getPosition()
{
	return m_Circle.getPosition();
}

Vector2f Ball::getCenter()
{
	return Ball::getPosition();
}

float Ball::getRestituion()
{
	return m_Restitution;
}

void Ball::setVelocity(Vector2f velocity)
{
	m_Velocity = velocity;
}

Vector2f Ball::getVelocity()
{
	return m_Velocity;
}

CircleShape Ball::getCircle()
{
	return m_Circle;
}

void Ball::reset(float direction)
{
	m_Position = START_POSITION;
	m_Velocity = START_VELOCITY * direction;
	m_Circle.setPosition(m_Position);
}