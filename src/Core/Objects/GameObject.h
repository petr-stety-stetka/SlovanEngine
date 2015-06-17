#pragma once

#include "../VertexData/VertexArrayObject.h"
#include <glm/vec3.hpp>

/**
 * In Alpha stage!!!
 * Now it is only for testing other part of engine!
 */
class GameObject
{
private:
	glm::vec3 position;
	glm::vec3 scale;
	VertexArrayObject vertexData;
	unsigned int numberOfVertices;
public:
	void set(std::vector <GLfloat> *vertices, std::vector <GLuint> attribute, std::vector <GLuint> size,
	         unsigned int numberOfVertices);

	void draw();
};