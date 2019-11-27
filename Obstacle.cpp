#define _USE_MATH_DEFINES
#include "Obstacle.h"
#include "TextureHolder.h"
#include <iostream>
#include <cmath>

Obstacle::Obstacle()
{
	m_Rect.setSize(Vector2f(200, 30));
}

void Obstacle::spawn(Vector2f position, float restitution, float angle)
{
	
	m_Rect.setPosition(position);
	m_Rect.setOrigin(100, 15);
	m_angle = angle;
	m_Rect.setRotation(m_angle);
	m_Restitution = restitution;
	m_norm = (m_Rect.getPoint(3) + m_Rect.getPoint(2)) * 0.5f - m_Rect.getOrigin()/*+m_Rect.getPosition()*/;
	m_norm = m_norm / sqrt(pow(m_norm.x, 2) + pow(m_norm.y, 2));
	m_norm = Vector2f(m_norm.x * cos(m_angle*M_PI/180) - m_norm.y * sin(m_angle * M_PI / 180),
		m_norm.x * sin(m_angle * M_PI / 180) + m_norm.y * cos(m_angle * M_PI / 180));
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

Vector2f* Obstacle::getLines()
{
	Vector2f lines[4];
	lines[0] = m_Rect.getPoint(0) - m_Rect.getPoint(1) + m_Rect.getPosition();
	lines[1] = m_Rect.getPoint(1) - m_Rect.getPoint(2) + m_Rect.getPosition();
	lines[2] = m_Rect.getPoint(2) - m_Rect.getPoint(3) + m_Rect.getPosition();
	lines[3] = m_Rect.getPoint(3) - m_Rect.getPoint(0) + m_Rect.getPosition();
	return lines;
}

float Obstacle::getAngle()
{
	return m_angle;
}


void Obstacle::collide(Ball& Ball)
{
	float restComb = (m_Restitution + Ball.getRestituion()) / 2;
	Vector2f exitVelocity = (Ball.getVelocity() - 
		2*(Ball.getVelocity().x * m_norm.x + Ball.getVelocity().y * m_norm.y) * m_norm)*restComb;
	Ball.setVelocity(exitVelocity);
	std::cout << '(' << exitVelocity.x << ',' << exitVelocity.y << ')' << '\n';
}	


