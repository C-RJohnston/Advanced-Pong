#define _USE_MATH_DEFINES
#include "Maths.h"

 float dot(Vector2f& vector1, Vector2f& vector2)
{
	return vector1.x * vector2.x + vector1.y + vector2.y;
}

Vector2f normal(Vector2f& vector)
{
	return vector * (1 / sqrt(dot(vector, vector)));
}

Vector2f project(Vector2f& vector1, Vector2f& vector2)
{
	return dot(vector1, vector2) * normal(vector2);
}
void printVect(Vector2f& vector)
{
	std::cout << '(' << vector.x << ',' << vector.y << ')' << '\n';
}

Vector2f rotate(Vector2f vector, float angle)
{
	return Vector2f(vector.x * cos(M_PI / 180 * angle) - vector.y * sin(M_PI / 180 * angle),
		vector.x * sin(M_PI / 180 * angle) + vector.y * cos(M_PI / 180 * angle));
}