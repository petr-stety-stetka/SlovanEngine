#pragma once

#include "../VertexData/VertexArrayObject.h"

#define GLM_FORCE_RADIANS
#include <glm/vec3.hpp>
#include "../GL/GLHeader.h"
#include <glm/gtc/quaternion.hpp>

/**
 * Game Object.
 */
class GameObject
{
private:
	glm::vec3 position;
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 rotationPivot;
	VertexArrayObject vertexData;
	GLuint numberOfVertices;

public:

	/**
	 * Create GameObject.
	 */
	GameObject();

	/**
	 * Set GameObject - vertices, shader program attributes, array of vertices size, numberOfVertices.
	 */
	void set(std::vector <GLfloat> *vertices, std::vector <GLuint> attribute, std::vector <GLuint> size,
	         GLuint numberOfVertices);

	void draw();

	/**
	 * Translate GameObject position to some place. Call this function in update().
	 */
	void translate(glm::vec3 distance);

	/**
	 * Scale up GameObject by scaleFactor. Call this function in update().
	 */
	void scaleUp(glm::vec3 scaleFactor);

	/**
	 * Rotate GameObject by local axis in quaternions. Call this function in update().
	 */
	void rotateLocal(glm::quat quaternion);

	/**
	 * Rotate GameObject by global axis in quaternions. Call this function in update().
	 */
	void rotateGlobal(glm::quat quaternion);

	/**
	 * Rotate GameObject by local axis in euler angles, in degrees.
	 * Order angles is XYZ! Call this function in update().
	 */
	void rotateLocal(glm::vec3 eulerAngle);

	/**
	 * Rotate GameObject by global axis in euler angles, in degrees.
	 * Order angles is XYZ! Call this function in update().
	 */
	void rotateGlobal(glm::vec3 eulerAngles);

	/**
	 * Return (global) rotation in quaternion.
	 */
	const glm::quat &getRotation() const;

	/**
	 * Return (global) rotation in euler angles in degrees. Order angles is XYZ!
	 */
	const glm::vec3 getRotation();

	/**
	 * Set rotation by quaternion in local axis. Call this function in update().
	 */
	void setRotationLocal(const glm::quat &quaternion);

	/**
	 * Set rotation by quaternion in global axis. Call this function in update().
	 */
	void setRotationGlobal(const glm::quat &quaternion);

	/**
	 * Set rotation by euler angles in degrees, in local axis.
	 * Order angles is XYZ! Call this function in update().
	 */
	void setRotationLocal(const glm::vec3 eulerAngles);

	/**
	 * Set rotation by euler angles in degrees, in global axis.
	 * Order angles is XYZ! Call this function in update().
	 */
	void setRotationGlobal(const glm::vec3 eulerAngles);

	/**
	 * Return position.
	 */
	const glm::vec3 &getPosition() const;

	/**
	 * Set position.
	 */
	void setPosition(const glm::vec3 &position);

	/**
	 * Return scale.
	 */
	const glm::vec3 &getScale() const;

	/**
	 * Set scale.
	 */
	void setScale(const glm::vec3 &scale);

	/**
	 * Return pivot of rotation. Pivot is in local position, no global.
	 * (Default is center of GameObject = 0.0, 0.0, 0.0)
	 */
	const glm::vec3 &getRotationPivot() const;

	/**
	 * Set pivot of rotation. Pivot is in local position, no global.
	 * (Default is center of GameObject = 0.0, 0.0, 0.0)
	 */
	void setRotationPivot(const glm::vec3 &pivot);
};