#include "Matrices.h"

glm::mat4 Matrices::modelMatrix;
glm::mat4 Matrices::viewMatrix;
glm::mat4 Matrices::projectionMatrix;
glm::mat4 Matrices::MVPMatrix;

const glm::mat4 &Matrices::getModelMatrix()
{
	return modelMatrix;
}

void Matrices::setModelMatrix(const glm::mat4 &modelMatrix)
{
	Matrices::modelMatrix = modelMatrix;
}

const glm::mat4 &Matrices::getViewMatrix()
{
	return viewMatrix;
}

void Matrices::setViewMatrix(const glm::mat4 &viewMatrix)
{
	Matrices::viewMatrix = viewMatrix;
}

const glm::mat4 &Matrices::getProjectionMatrix()
{
	return projectionMatrix;
}

void Matrices::setProjectionMatrix(const glm::mat4 &projectionMatrix)
{
	Matrices::projectionMatrix = projectionMatrix;
}

const glm::mat4 &Matrices::getMVPMatrix()
{
	return MVPMatrix;
}

void Matrices::setMVPMatrix(const glm::mat4 &MVPMatrix)
{
	Matrices::MVPMatrix = MVPMatrix;
}

glm::mat4 Matrices::identity()
{
	glm::mat4 identityMatrix;
	return identityMatrix;
}

