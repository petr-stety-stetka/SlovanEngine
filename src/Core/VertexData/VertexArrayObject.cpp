#include "VertexArrayObject.h"

void VertexArrayObject::set(std::vector <GLfloat> *vertices, std::vector <GLuint> attribute, std::vector <GLuint> size)
{
	glGenVertexArrays(1, &VAOID);
	glBindVertexArray(VAOID);

	glGenBuffers(1, &VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, VBOID);
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr) sizeof(GL_FLOAT) * vertices->size(), vertices->data(), GL_STATIC_DRAW);

	std::vector <std::size_t> sizeOfOffset(size.size());

	GLsizei stride = 0;
	std::size_t dataSize = 0;
	for(unsigned int i = 0; i < size.size(); i++)
	{
		stride += size[i];
		if(i != 0)
		{
			dataSize += size[i - 1];
			sizeOfOffset[i] = sizeof(GL_FLOAT) * dataSize;
		}
		else
		{
			sizeOfOffset[i] = 0;
		}
	}

	GLsizei strideInByte = GLsizei(sizeof(GL_FLOAT) * (stride));

	for(unsigned int i = 0; i < attribute.size(); i++)
	{
		glEnableVertexAttribArray(attribute[i]);
		glVertexAttribPointer(attribute[i], size[i], GL_FLOAT, GL_FALSE, strideInByte,
		                      (GLvoid *) sizeOfOffset[i]);
	}

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