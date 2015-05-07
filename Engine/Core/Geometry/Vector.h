#pragma once

class Vector
{
private:
	float x;
	float y;
	float z;

public:
	Vector(float x, float y, float z);

	float getX() const;

	float getY() const;

	float getZ() const;
};