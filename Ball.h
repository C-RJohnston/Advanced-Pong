#pragma once
#include <SFMl/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	
	Sprite m_Sprite;

	Vector2f m_Gravity;

	Vector2f m_Position;
	Vector2f m_Velocity;

	Texture m_Texture;

public:

	Ball();

	void spawn(Vector2f startPosition, Vector2f startVelocity, Vector2f gravity);

	FloatRect getPosition();

	Sprite getSprite();

	Vector2f getCenter();

	void update(float elapsedTime);
};