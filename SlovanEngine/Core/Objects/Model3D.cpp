#include "Model3D.h"
#include "../Shader/Matrices.h"
#include "../../../external/glm/gtc/matrix_transform.hpp"
#include "../../../external/glm/gtx/quaternion.hpp"
#include "../../../external/glm/gtx/euler_angles.hpp"

Model3D::Model3D()
{
	position = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
	rotationPivot = glm::vec3(0.0f);
}

void Model3D::setModel(std::string name)
{
	shaderProgram = ShaderPrograms::shaderPrograms::AssimpProgram;
	name = "Resources/models/" + name;
	model.loadModel(&name);
}

void Model3D::draw()
{
	Matrices::setModelMatrix(Matrices::identity());

	Matrices::setModelMatrix(glm::translate(Matrices::getModelMatrix(), position));
	Matrices::setModelMatrix(Matrices::getModelMatrix() * glm::toMat4(rotation));
	Matrices::setModelMatrix(glm::translate(Matrices::getModelMatrix(), rotationPivot));
	Matrices::setModelMatrix(glm::scale(Matrices::getModelMatrix(), scale));

	model.draw(&shaderProgram);
}

void Model3D::translate(glm::vec3 distance)
{
	position = position + distance;
}

void Model3D::scaleUp(glm::vec3 scaleFactor)
{
	scale = scale + scaleFactor;
}

void Model3D::rotateLocal(glm::quat quaternion)
{
	rotation = rotation * quaternion;
}

void Model3D::rotateGlobal(glm::quat quaternion)
{
	rotation = quaternion * rotation;
}

void Model3D::rotateLocal(glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
	rotation = rotation * glm::quat(eulerAnglesInRadians);
}

void Model3D::rotateGlobal(glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
	rotation = glm::quat(eulerAnglesInRadians) * rotation;
}

const glm::quat &Model3D::getRotation() const
{
	return rotation;
}

const glm::vec3 Model3D::getRotation()
{
	glm::vec3 eulerAngles = glm::eulerAngles(rotation);
	return glm::vec3(glm::degrees(eulerAngles));
}

void Model3D::setRotationLocal(const glm::quat &quaternion)
{
	Model3D::rotation = quaternion;
}

void Model3D::setRotationGlobal(const glm::quat &quaternion)
{
	Model3D::rotation = quaternion;
}

void Model3D::setRotationLocal(const glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
	Model3D::rotation = glm::quat(eulerAnglesInRadians);
}

void Model3D::setRotationGlobal(const glm::vec3 eulerAngles)
{
	glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
	Model3D::rotation = glm::quat(eulerAnglesInRadians);
}

const glm::vec3 &Model3D::getPosition() const
{
	return position;
}

void Model3D::setPosition(const glm::vec3 &position)
{
	Model3D::position = position;
}

const glm::vec3 &Model3D::getScale() const
{
	return scale;
}

void Model3D::setScale(const glm::vec3 &scale)
{
	Model3D::scale = scale;
}

const glm::vec3 &Model3D::getRotationPivot() const
{
	return rotationPivot;
}

void Model3D::setRotationPivot(const glm::vec3 &pivot)
{
	Model3D::rotationPivot = pivot;
}


const ShaderPrograms::shaderPrograms &Model3D::getShaderProgram() const
{
	return shaderProgram;
}

void Model3D::setShaderProgram(const ShaderPrograms::shaderPrograms &shaderProgram)
{
	Model3D::shaderProgram = shaderProgram;
}