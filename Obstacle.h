#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

using namespace sf;

class Obstacle
{
protected:


	Texture m_Texture;

	float m_Restitution;

	RectangleShape m_Rect;

	float m_Angle;
	
	Vector2f m_Norm;

	Vector2f m_Velocity;

	Vector2f m_Position;


public:

	Obstacle();

	void calcNorm();

	void spawn(Vector2f position, float restitution, float angle, Vector2f velocity=Vector2f(0,0));

	Vector2f getPosition();

	Vector2f getVelocity();

	void handleInput();

	void update(float timeElapsed);

	void setPosition(Vector2f Position);

	RectangleShape getRect();

	Vector2f getCenter();

	Vector2f getCorners(int index);

	float getAngle();

	void setAngle(float angle);

	void collide(Ball& ball);
};
