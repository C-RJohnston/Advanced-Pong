#define _USE_MATH_DEFINES
#include "Obstacle.h"
#include "TextureHolder.h"
#include <iostream>
#include <cmath>

Obstacle::Obstacle()
{
	m_Rect.setSize(Vector2f(200, 30));
}

void Obstacle::spawn(Vector2f position, float restitution)
{
	
	m_Rect.setPosition(position);
	m_Rect.setOrigin(100, 15);
	m_Rect.setRotation(45);
	m_Restitution = restitution;
}

Vector2f Obstacle::getPosition()
{
	return m_Rect.getPosition();
}


RectangleShape Obstacle::getRect()
{
	return m_Rect;
}

Vector2f Obstacle::getCenter()
{
	return m_Rect.getOrigin();
}

FloatRect Obstacle::boundBox()
{
	return m_Rect.getGlobalBounds();
}

void Obstacle::collide(Ball& Ball)
{
	float restComb = (m_Restitution + Ball.getRestituion()) / 2;
	Vector2f topLeft = Vector2f(m_Rect.getPoint(3).x * sin(m_Rect.getRotation()) + m_Rect.getPosition().x, m_Rect.getPoint(3).y * cos(m_Rect.getRotation()) + m_Rect.getPosition().y);
	Vector2f topRight = Vector2f(m_Rect.getPoint(2).x * sin(m_Rect.getRotation()) + m_Rect.getPosition().x, m_Rect.getPoint(2).y * cos(m_Rect.getRotation()) + m_Rect.getPosition().y);
	Vector2f top = topRight - topLeft;
	float angle = 90 - acos((Ball.getVelocity().x * top.x + Ball.getVelocity().y * top.y) / (sqrt(pow(Ball.getVelocity().x, 2) + pow(Ball.getVelocity().y, 2)) * sqrt(pow(top.x, 2) + pow(top.y, 2))))*180/M_PI;
	Ball.setVelocity(Vector2f(cos(2 * angle*M_PI/180) * Ball.getVelocity().x + sin(2 * angle * M_PI / 180) * Ball.getVelocity().y, sin(2 * angle * M_PI / 180) * Ball.getVelocity().x - cos(2 * angle * M_PI / 180) * Ball.getVelocity().y));
	std::cout << angle;
} 

