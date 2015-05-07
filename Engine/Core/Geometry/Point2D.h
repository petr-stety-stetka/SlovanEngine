#pragma once

#include "Vector.h"

class Point2D
{
private:
	float x;
	float y;

public:
	Point2D(float x, float y);

	float getX() const;

	float getY() const;

	void translateX(float distance);

	void translateY(float distance);

	void translate(float xDistance, float yDistance);

	void translate(Vector vector);
};