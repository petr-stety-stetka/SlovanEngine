#pragma once

#include "../../../external/glm/mat4x4.hpp"

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
	/**
	 * Get model matrix.
	 */
	static const glm::mat4 &getModelMatrix();

	/**
	 * Set model matrix.
	 */
	static void setModelMatrix(const glm::mat4 &modelMatrix);;

	/**
	 * Get view matrix.
	 */
	static const glm::mat4 &getViewMatrix();

	/**
	 * Set view matrix.
	 */
	static void setViewMatrix(const glm::mat4 &viewMatrix);

	/**
	 * Get projection matrix.
	 */
	static const glm::mat4 &getProjectionMatrix();

	/**
	 * Set projection matrix.
	 */
	static void setProjectionMatrix(const glm::mat4 &projectionMatrix);

	/**
	 * Get model-view-projection matrix.
	 */
	static const glm::mat4 &getMVPMatrix();

	/**
	 * Set model-view-projection matrix.
	 */
	static void setMVPMatrix(const glm::mat4 &MVPMatrix);

	/**
	 * Return identity matrix.
	 */
	static glm::mat4 identity();
};