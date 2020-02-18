#pragma once
#include "Obstacle.h"

class Paddle : public Obstacle
{
protected:

	float m_RotVel;

	bool m_leftPressed;

	bool m_rightPressed;

	bool m_upPressed;

	bool m_downPressed;

	int m_Score;


public:
	void virtual handleInput() = 0;
	void update(float elapsedTime);
	int getScore();
	void setScore(int score);
	void scoreUp();


};