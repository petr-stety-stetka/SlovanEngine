#pragma once

#include <glm/mat4x4.hpp>

class Matrices
{
private:
	/** Model Matrix */
	static glm::mat4 modelMatrix;
	/** View Matrix */
	static glm::mat4 viewMatrix;
	/** Projection Matrix */
	static glm::mat4 projectionMatrix;
	/** Model + View + Projection Matrix */
	static glm::mat4 MVPMatrix;

public:
	static const glm::mat4 &getModelMatrix();

	static void setModelMatrix(const glm::mat4 &modelMatrix);;

	static const glm::mat4 &getViewMatrix();

	static void setViewMatrix(const glm::mat4 &viewMatrix);

	static const glm::mat4 &getProjectionMatrix();

	static void setProjectionMatrix(const glm::mat4 &projectionMatrix);

	static const glm::mat4 &getMVPMatrix();

	static void setMVPMatrix(const glm::mat4 &MVPMatrix);
};