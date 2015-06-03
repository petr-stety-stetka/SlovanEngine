#pragma once

#include "../GL/GLHeader.h"
#include <vector>

/**
 * Vertex Array Object (VAO) is for store vertices (positions, normals, texture coordinations..).
 */
class VertexArrayObject
{
private:
	GLuint VAOID;
	GLuint VBOID;

	VertexArrayObject()
	{ }

public:

	/**
	 * Create new Vertex Array Object (VAO)
	 * @param vertices Data for store.
	 * @param attribute ID of vertex attributes of shader program.
	 * @param size Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4
	 *              -> ex. Constants::POSITION_3D_DATA_SIZE, must be sorted as in vertices data!
	 */
	VertexArrayObject(std::vector <GLfloat> *vertices, std::vector <GLuint> attribute, std::vector <GLuint> size);

	~VertexArrayObject();

	/**
	 * Get ID of VAO as OpenGL object.
	 */
	GLuint getID() const;
};