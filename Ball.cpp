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
	m_Velocity = startVelocity;

	m_Gravity = gravity;

	m_Restitution = restitution;
	m_Circle.setOrigin(Vector2f(10,10));
	m_Circle.setPosition(m_Position);

	
}

FloatRect Ball::boundBox()
{
	return m_Circle.getGlobalBounds();
}

void Ball::update(float elapsedTime)
{
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
	return m_Circle.getOrigin()+Ball::getPosition();
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