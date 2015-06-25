#pragma once

#include "../GL/GLHeader.h"

#define GLM_FORCE_RADIANS

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


class Camera
{
private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::quat rotation;
	glm::vec3 scale;

public:

	/**
	 * Create camera.
	 *
	 * @param position Position of camera.
	 * @param front Front plane position.
	 */
	Camera(glm::vec3 position = glm::vec3(0.0f), glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f));

	/**
	 * Set Perspective projection. Call this function in render().
	 */
	void setPerspectiveProjection(GLfloat fovyInDegrees, GLfloat aspect, GLfloat zNear, GLfloat zFar);

	/**
	 * Set Orthographic projection. Call this function in render().
	 */
	void setOrthoProjection(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);

	/**
	 * Update camera position, rotation... Call this function in update().
	 */
	void update();

	/**
	 * Translate camera position to some place. Call this function in update().
	 */
	void translate(glm::vec3 distance);

	/**
	 * Scale up camera by scaleFactor. Call this function in update().
	 */
	void scaleUp(glm::vec3 scaleFactor);

	/**
	 * Get position.
	 */
	const glm::vec3 &getPosition() const;

	/**
	 * Set position.
	 */
	void setPosition(const glm::vec3 &position);

	/**
	 * Return front.
	 */
	const glm::vec3 &getFront() const;

	/**
	 * Set front.
	 */
	void setFront(const glm::vec3 &front);

	/**
	 * Return up.
	 */
	const glm::vec3 &getUp() const;

	/**
	 * Set up.
	 */
	void setUp(const glm::vec3 &up);

	/**
	 * Return scale.
	 */
	glm::vec3 getScale() const;

	/**
	 * Set scale.
	 */
	void setScale(glm::vec3 scale);

	/**
	 * Return (global) rotation in quaternion.
	 */
	const glm::quat &getRotation() const;

	/**
	 * Return (global) rotation in euler angles in degrees. Order angles is XYZ!
	 */
	const glm::vec3 getRotation();

	/**
	 * Set rotation by quaternion. Call this function in update().
	 */
	void setRotation(const glm::quat &quaternion);

	/**
	 * Set rotation by euler angles in degrees.
	 * Order angles is XYZ! Call this function in update().
	 */
	void setRotation(glm::vec3 eulerAngles);

	/**
	 * Rotate camera in quaternions. Call this function in update().
	 */
	void rotate(glm::quat quaternion);

	/**
	 * Rotate GameObject in euler angles, in degrees.
	 * Order angles is XYZ! Call this function in update().
	 */
	void rotate(glm::vec3 eulerAngles);
};