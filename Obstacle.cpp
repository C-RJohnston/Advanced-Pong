#define _USE_MATH_DEFINES
#include "Obstacle.h"
#include "TextureHolder.h"
#include <iostream>
#include <cmath>
#include "Maths.h"

Obstacle::Obstacle()
{
	m_Rect.setSize(Vector2f(200, 30));
}

void Obstacle::spawn(Vector2f position, float restitution, float angle)
{
	m_Rect.setOrigin(100, 15);
	m_Rect.setPosition(position);
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
	return m_Rect.getPosition();
}

float Obstacle::getAngle()
{
	return m_angle;
}

Vector2f Obstacle::getCorners(int index)
{
	Vector2f corners[4];
	Vector2f unrot0 = Vector2f(Obstacle::getCenter().x - m_Rect.getSize().x / 2, Obstacle::getCenter().y + m_Rect.getSize().y / 2);
	corners[0] = rotate(unrot0,m_angle);
	Vector2f unrot1 = Vector2f(Obstacle::getCenter().x + m_Rect.getSize().x / 2, Obstacle::getCenter().y + m_Rect.getSize().y / 2);
	corners[1] = rotate(unrot1, m_angle);
	Vector2f unrot2 = Vector2f(Obstacle::getCenter().x - m_Rect.getSize().x / 2, Obstacle::getCenter().y - m_Rect.getSize().y / 2);
	corners[2] = rotate(unrot2, m_angle);
	Vector2f unrot3 = Vector2f(Obstacle::getCenter().x + m_Rect.getSize().x / 2, Obstacle::getCenter().y - m_Rect.getSize().y / 2);
	corners[3] = rotate(unrot3,m_angle);
	return corners[index];
}

void Obstacle::collide(Ball& Ball)
{
	float restComb = (m_Restitution + Ball.getRestituion()) / 2;
	Vector2f exitVelocity = (Ball.getVelocity() - 
		2*(Ball.getVelocity().x * m_norm.x + Ball.getVelocity().y * m_norm.y) * m_norm)*restComb;
	Ball.setVelocity(exitVelocity);
	std::cout << '(' << exitVelocity.x << ',' << exitVelocity.y << ')' << '\n';
}	


