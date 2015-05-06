#include "../../ForUse/Geometry/Vector.h"

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z)
{ }

float Vector::getX() const
{
	return x;
}

float Vector::getY() const
{
	return y;
}

float Vector::getZ() const
{
	return z;
}