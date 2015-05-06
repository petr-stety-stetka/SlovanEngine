#include "../../ForUse/Geometry/Point3D.h"

Point3D::Point3D(float x, float y, float z) : x(x), y(y), z(z)
{ }

float Point3D::getX() const
{
	return x;
}

float Point3D::getY() const
{
	return y;
}

float Point3D::getZ() const
{
	return z;
}

void Point3D::translateX(float distance)
{
	x += distance;
}

void Point3D::translateY(float distance)
{
	y += distance;
}

void Point3D::translateZ(float distance)
{
	z += distance;
}

void Point3D::translate(float xDistance, float yDistance, float zDistance)
{
	x += xDistance;
	y += yDistance;
	z += zDistance;
}

void Point3D::translate(Vector vector)
{
	x += vector.getX();
	y += vector.getY();
	z += vector.getZ();
}