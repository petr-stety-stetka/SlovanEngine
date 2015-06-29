#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include "../Shader/Matrices.h"

Camera::Camera(glm::vec3 position, glm::vec3 front)
{
	this->position = position;
	this->front = front;
	this->up = glm::vec3(0.0f, 1.0f, 0.0f);
	scale = glm::vec3(1.0f);
}

void Camera::setPerspectiveProjection(GLfloat fovyInDegrees, GLfloat aspect, GLfloat zNear, GLfloat zFar)
{
	Matrices::setProjectionMatrix(glm::perspective(glm::radians(fovyInDegrees), aspect, zNear, zFar));
}

void Camera::setOrthoProjection(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
{
	Matrices::setProjectionMatrix(glm::ortho(left, right, bottom, top, zNear, zFar));
}

void Camera::update()
{
	glm::mat4 matrix(glm::toMat4(rotation));
	matrix *= glm::lookAt(position, position + front, up);
	matrix = glm::scale(matrix, scale);
	Matrices::setViewMatrix(matrix);
}

void Camera::translate(glm::vec3 distance)
{
	position = position + distance;
}

void Camera::scaleUp(glm::vec3 scaleFactor)
{
	scale = scale + scaleFactor;
}

const glm::vec3 &Camera::getPosition() const
{
	return position;
}

void Camera::setPosition(const glm::vec3 &position)
{
	Camera::position = position;
}

const glm::vec3 &Camera::getFront() const
{
	return front;
}

void Camera::setFront(const glm::vec3 &front)
{
	Camera::front = front;
}

const glm::vec3 &Camera::getUp() const
{
	return up;
}

void Camera::setUp(const glm::vec3 &up)
{
	Camera::up = up;
}

glm::vec3 Camera::getScale() const
{
	return scale;
}

void  Camera::setScale(glm::vec3 scale)
{
	Camera::scale = scale;
}

const glm::quat &Camera::getRotation() const
{
	return rotation;
}

const glm::vec3 Camera::getRotation()
{
	glm::vec3 eulerAngles = glm::eulerAngles(rotation);
	return glm::vec3(glm::degrees(eulerAngles));
}

void Camera::setRotation(const glm::quat &quaternion)
{
	Camera::rotation = quaternion;
}

void Camera::setRotation(glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));

	rotation = glm::quat(eulerAnglesInRadians);
}

void Camera::rotate(glm::quat quaternion)
{
	rotation = rotation * quaternion;
}

void Camera::rotate(glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));

	rotation = rotation * glm::quat(eulerAnglesInRadians);
}