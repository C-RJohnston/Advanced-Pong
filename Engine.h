#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Ball.h"

using namespace sf;

class Engine
{
private:
	//The texture holder
	TextureHolder th;

	//A pinball
	Ball m_Ball;

	//the force of gravity experienced by the ball as a constant value in pixels/second^2
	const Vector2f g = Vector2f(0, 1000);

	//a Rendew Window for the game and the views (player view, HUD view, and BG view)
	RenderWindow m_Window;
	View m_BGView;
	View m_View;
	View m_HudView;

	//The sprite and texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// How much time is left in the current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	//the Engine constructor
	Engine();

	//will run the game
	void run();
};