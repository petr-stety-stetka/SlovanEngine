#include "../../ForUse/Geometry/Point2D.h"

Point2D::Point2D(float x, float y) : x(x), y(y)
{ }

float Point2D::getX() const
{
	return x;
}

float Point2D::getY() const
{
	return y;
}

void Point2D::translateX(float distance)
{
	x += distance;
}

void Point2D::translateY(float distance)
{
	y += distance;
}

void Point2D::translate(float xDistance, float yDistance)
{
	x += xDistance;
	y += yDistance;
}

void Point2D::translate(Vector vector)
{
	x += vector.getX();
	y += vector.getY();
}