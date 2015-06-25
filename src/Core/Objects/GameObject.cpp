#include "GameObject.h"
#include "../ShaderPrograms/TestProgram.h"
#include "../Shader/Matrices.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

GameObject::GameObject()
{
	position = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
	rotationPivot = glm::vec3(0.0f);
}

void GameObject::set(std::vector <GLfloat> *vertices, std::vector <GLuint> attribute, std::vector <GLuint> size,
                     GLuint numberOfVertices)
{
	vertexData.set(vertices, attribute, size);
	GameObject::numberOfVertices = numberOfVertices;
}

void GameObject::draw()
{
	Matrices::setModelMatrix(Matrices::identity());

	Matrices::setModelMatrix(glm::translate(Matrices::getModelMatrix(), position));
	Matrices::setModelMatrix(Matrices::getModelMatrix() * glm::toMat4(rotation));
	Matrices::setModelMatrix(glm::translate(Matrices::getModelMatrix(), rotationPivot));
	Matrices::setModelMatrix(glm::scale(Matrices::getModelMatrix(), scale));

	TestProgram::draw(vertexData.getID(), numberOfVertices);
}

void GameObject::translate(glm::vec3 distance)
{
	position = position + distance;
}

void GameObject::scaleUp(glm::vec3 scaleFactor)
{
	scale = scale + scaleFactor;
}

void GameObject::rotateLocal(glm::quat quaternion)
{
	rotation = rotation * quaternion;
}

void GameObject::rotateGlobal(glm::quat quaternion)
{
	rotation = quaternion * rotation;
}

void GameObject::rotateLocal(glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
	rotation = rotation * glm::quat(eulerAnglesInRadians);
}

void GameObject::rotateGlobal(glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
	rotation = glm::quat(eulerAnglesInRadians) * rotation;
}

const glm::quat &GameObject::getRotation() const
{
	return rotation;
}

const glm::vec3 GameObject::getRotation()
{
	glm::vec3 eulerAngles = glm::eulerAngles(rotation);
	return glm::vec3(glm::degrees(eulerAngles));
}

void GameObject::setRotationLocal(const glm::quat &quaternion)
{
	GameObject::rotation = quaternion;
}

void GameObject::setRotationGlobal(const glm::quat &quaternion)
{
	GameObject::rotation = quaternion;
}

void GameObject::setRotationLocal(const glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
	this->rotation = glm::quat(eulerAnglesInRadians);
}

void GameObject::setRotationGlobal(const glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
	this->rotation = glm::quat(eulerAnglesInRadians);
}

const glm::vec3 &GameObject::getPosition() const
{
	return position;
}

void GameObject::setPosition(const glm::vec3 &position)
{
	GameObject::position = position;
}

const glm::vec3 &GameObject::getScale() const
{
	return scale;
}

void GameObject::setScale(const glm::vec3 &scale)
{
	GameObject::scale = scale;
}

const glm::vec3 &GameObject::getRotationPivot() const
{
	return rotationPivot;
}

void GameObject::setRotationPivot(const glm::vec3 &pivot)
{
	GameObject::rotationPivot = pivot;
}