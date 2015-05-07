#pragma once

#include "Vector.h"

class Point3D
{
private:
	float x;
	float y;
	float z;

public:
	Point3D(float x, float y, float z);

	float getX() const;

	float getY() const;

	float getZ() const;

	void translateX(float distance);

	void translateY(float distance);

	void translateZ(float distance);

	void translate(float xDistance, float yDistance, float zDistance);

	void translate(Vector vector);
};