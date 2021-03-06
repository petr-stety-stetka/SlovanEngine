#pragma once

#include "../VertexData/VertexArrayObject.h"

#define GLM_FORCE_RADIANS

#include "../../../external/glm/vec3.hpp"
#include "../GL/GLHeader.h"
#include "../ShaderPrograms/ShaderPrograms.h"
#include "../../../external/glm/gtc/quaternion.hpp"

/**
 * Game Object.
 */
class BasicGeometryShape {
private:
    glm::vec3 position;
    glm::vec3 scale;
    glm::quat rotation;
    glm::vec3 rotationPivot;
    VertexArrayObject vertexData;
    GLuint numberOfVertices;
    ShaderPrograms::shaderPrograms shaderProgram;

public:

    /**
     * Create Model3D.
     */
    BasicGeometryShape();

    /**
     * Set Model3D - vertices, shader program (used for draw), shader program attributes, array of vertices size,
     *                  number of vertices.
     */
    void set(std::vector<GLfloat> *vertices, const ShaderPrograms::shaderPrograms shaderProgram,
             std::vector<GLuint> attribute, std::vector<GLuint> size, GLuint numberOfVertices);

    /**
     * Render Model3D.
     */
    void draw();

    /**
     * Translate Model3D position to some place. Call this function in update().
     */
    void translate(glm::vec3 distance);

    /**
     * Scale up Model3D by scaleFactor. Call this function in update().
     */
    void scaleUp(glm::vec3 scaleFactor);

    /**
     * Rotate Model3D by local axis in quaternions. Call this function in update().
     */
    void rotateLocal(glm::quat quaternion);

    /**
     * Rotate Model3D by global axis in quaternions. Call this function in update().
     */
    void rotateGlobal(glm::quat quaternion);

    /**
     * Rotate Model3D by local axis in euler angles, in degrees.
     * Order angles is XYZ! Call this function in update().
     */
    void rotateLocal(glm::vec3 eulerAngle);

    /**
     * Rotate Model3D by global axis in euler angles, in degrees.
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
     * (Default is center of Model3D = 0.0, 0.0, 0.0)
     */
    const glm::vec3 &getRotationPivot() const;

    /**
     * Set pivot of rotation. Pivot is in local position, no global.
     * (Default is center of Model3D = 0.0, 0.0, 0.0)
     */
    void setRotationPivot(const glm::vec3 &pivot);

    /**
     * Get shader program used for draw this GameObjects.
     */
    const ShaderPrograms::shaderPrograms &getShaderProgram() const;

    /**
     * Set shader program used for draw this GameObjects.
     */
    void setShaderProgram(const ShaderPrograms::shaderPrograms &shaderProgram);
};