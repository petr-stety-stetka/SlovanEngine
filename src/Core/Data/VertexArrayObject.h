#pragma once

#include "../GL/GLHeader.h"
#include <cstddef>

/**
 * Vertex Array Object (VAO) is for store vertices (normals, texture coordination..).
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
	 * @param sizeOfVertices Size of vertices: "sizeof(yourVertices)"
	 * @param attribute ID of vertex attribute of shader program.
	 */
	VertexArrayObject(const GLvoid *vertices, std::size_t sizeOfVertices, GLuint attribute);

	~VertexArrayObject();

	/**
	 * Get ID of VAO as OpenGL object.
	 */
	GLuint getID() const;
};