#include "GameObject.h"
#include "SlovanEngine/Core/ShaderPrograms/TestProgram.h"

void GameObject::set(std::vector <GLfloat> *vertices, std::vector <GLuint> attribute, std::vector <GLuint> size,
                     unsigned int numberOfVertices)
{
	vertexData.set(vertices, attribute, size);
	GameObject::numberOfVertices = numberOfVertices;
}

void GameObject::draw()
{
	TestProgram::draw(vertexData.getID(), numberOfVertices);
}