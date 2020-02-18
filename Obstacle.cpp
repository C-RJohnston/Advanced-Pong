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

void Obstacle::spawn(Vector2f position, float restitution, float angle, Vector2f velocity)
{
	m_Rect.setOrigin(100, 15);
	m_Position = position;
	m_Rect.setPosition(position);
	m_Angle = angle;
	m_Velocity = velocity;
	m_Rect.setRotation(m_Angle);
	m_Restitution = restitution;

}


void Obstacle::calcNorm()
{
	m_Norm = (m_Rect.getPoint(3) + m_Rect.getPoint(2)) * 0.5f - m_Rect.getOrigin();
	m_Norm = m_Norm / sqrt(pow(m_Norm.x, 2) + pow(m_Norm.y, 2));
	m_Norm = Vector2f(m_Norm.x * cos(m_Angle * M_PI / 180) - m_Norm.y * sin(m_Angle * M_PI / 180),
		m_Norm.x * sin(m_Angle * M_PI / 180) + m_Norm.y * cos(m_Angle * M_PI / 180));
}

Vector2f Obstacle::getPosition()
{
	return m_Position;
}

void Obstacle::setPosition(Vector2f position)
{
	m_Rect.setPosition(position);
}

Vector2f Obstacle::getVelocity()
{
	return m_Velocity;
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
	return m_Angle;
}

void Obstacle::setAngle(float angle)
{
	m_Angle = angle;
	m_Rect.setRotation(angle);
}

Vector2f Obstacle::getCorners(int index)
{
	Vector2f corners[4];
	Vector2f unrot0 = Vector2f(Obstacle::getCenter().x - m_Rect.getSize().x / 2, Obstacle::getCenter().y + m_Rect.getSize().y / 2);
	corners[0] = rotate(unrot0,m_Angle,Obstacle::getCenter());
	Vector2f unrot1 = Vector2f(Obstacle::getCenter().x + m_Rect.getSize().x / 2, Obstacle::getCenter().y + m_Rect.getSize().y / 2);
	corners[1] = rotate(unrot1, m_Angle, Obstacle::getCenter());
	Vector2f unrot2 = Vector2f(Obstacle::getCenter().x - m_Rect.getSize().x / 2, Obstacle::getCenter().y - m_Rect.getSize().y / 2);
	corners[2] = rotate(unrot2, m_Angle, Obstacle::getCenter());
	Vector2f unrot3 = Vector2f(Obstacle::getCenter().x + m_Rect.getSize().x / 2, Obstacle::getCenter().y - m_Rect.getSize().y / 2);
	corners[3] = rotate(unrot3,m_Angle, Obstacle::getCenter());
	return corners[index];
}

void Obstacle::collide(Ball& Ball)
{
	calcNorm();
	float restComb = (m_Restitution + Ball.getRestituion()) / 2;
	Vector2f exitVelocity = (Ball.getVelocity() - 
		2*(Ball.getVelocity().x * m_Norm.x + Ball.getVelocity().y * m_Norm.y) * m_Norm)*restComb;
	Vector2f delta = Ball.getPosition() - m_Position;


	Ball.setVelocity(exitVelocity);
	printVect(exitVelocity);
}	


