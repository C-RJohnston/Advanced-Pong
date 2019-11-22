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

public:

	Obstacle();

	void spawn(Vector2f position, float restitution);

	Vector2f getPosition();

	RectangleShape getRect();

	Vector2f getCenter();

	FloatRect boundBox();

	void collide(Ball& ball);
};
