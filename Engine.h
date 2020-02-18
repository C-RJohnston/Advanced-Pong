#pragma once
#include <SFML/Graphics.hpp>
#include <sfml/Audio.hpp>
#include "TextureHolder.h"
#include "Ball.h"
#include "Obstacle.h"
#include "Player1.h"
#include "Player2.h"

using namespace sf;

class Engine
{
private:
	//The texture holder
	TextureHolder th;

	//A pinball
	Ball m_Ball;

	//players
	Player1 m_P1;
	Player2 m_P2;

	SoundBuffer m_hitBuffer;
	SoundBuffer m_scoreBuffer;
	SoundBuffer m_winBuffer;

	Sound m_hitSound;
	Sound m_scoreSound;
	Sound m_winSound;

	//the force of gravity experienced by the ball as a constant value in pixels/second^2
	const Vector2f g = Vector2f(0, 800);

	//a Render Window for the game and the views (player view, HUD view, and BG view)
	RenderWindow m_Window;
	View m_BGView;
	View m_View;
	View m_HudView;

	Texture m_BackgroundTexture;
	Sprite m_BackgroundSprite;

	// How much time is left in the current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//score
	Font m_Font;
	Text m_1ScoreText;
	Text m_2ScoreText;
	Text m_DividerText;

	//total score of the game
	int m_TotalScore = 0;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
	bool detectCollisions(Ball& ball, Obstacle& obstacle);

public:
	//the Engine constructor
	Engine();

	//will run the game
	void run();
};