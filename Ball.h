#pragma once
#include <SFMl/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	
	float m_Restitution;

	Vector2f START_POSITION;
	Vector2f START_VELOCITY;

	Vector2f m_Gravity;

	Vector2f m_Position;
	Vector2f m_Velocity;

	CircleShape m_Circle;

public:

	Ball();

	void spawn(Vector2f startPosition, Vector2f startVelocity, Vector2f gravity, float restitution);

	Vector2f getPosition();

	CircleShape getCircle();

	Vector2f getCenter();

	float getRestituion();

	FloatRect boundBox();

	void setVelocity(Vector2f velocity);

	Vector2f getVelocity();

	void update(float elapsedTime);

	void reset(float direction);
};