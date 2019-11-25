#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

using namespace sf;

class Obstacle
{
private:


	Texture m_Texture;

	float m_Restitution;

	RectangleShape m_Rect;

	float m_angle;
	
	Vector2f m_norm;

public:

	Obstacle();

	void spawn(Vector2f position, float restitution, float angle);

	Vector2f getPosition();

	RectangleShape getRect();

	Vector2f getCenter();


	FloatRect boundBox();

	float getAngle();

	void collide(Ball& ball);
};
