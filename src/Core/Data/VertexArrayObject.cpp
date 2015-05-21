#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject(const GLvoid *vertices, std::size_t sizeOfVertices, GLuint attribute)
{
	glGenVertexArrays(1, &VAOID);
	glBindVertexArray(VAOID);

	glGenBuffers(1, &VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, VBOID);
	glBufferData(GL_ARRAY_BUFFER, sizeOfVertices, vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(attribute);
	glVertexAttribPointer(attribute, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArrayObject::~VertexArrayObject()
{
	glDeleteBuffers(1, &VBOID);
	glDeleteVertexArrays(1, &VAOID);
}

GLuint VertexArrayObject::getID() const
{
	return VAOID;
}