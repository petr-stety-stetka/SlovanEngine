#include "BasicGeometryShape.h"
#include "../Shader/Matrices.h"
#include "../../../external/glm/gtc/matrix_transform.hpp"
#include "../../../external/glm/gtx/quaternion.hpp"
#include "../../../external/glm/gtx/euler_angles.hpp"
#include "../ShaderPrograms/TestProgram.h"

BasicGeometryShape::BasicGeometryShape() {
    position = glm::vec3(0.0f);
    scale = glm::vec3(1.0f);
    rotationPivot = glm::vec3(0.0f);
}

void BasicGeometryShape::set(std::vector<GLfloat> *vertices, const ShaderPrograms::shaderPrograms shaderProgram,
                             std::vector<GLuint> attribute, std::vector<GLuint> size, GLuint numberOfVertices) {
    vertexData.set(vertices, attribute, size);
    BasicGeometryShape::numberOfVertices = numberOfVertices;
    BasicGeometryShape::shaderProgram = shaderProgram;
}

void BasicGeometryShape::draw() {
    Matrices::setModelMatrix(Matrices::identity());

    Matrices::setModelMatrix(glm::translate(Matrices::getModelMatrix(), position));
    Matrices::setModelMatrix(Matrices::getModelMatrix() * glm::toMat4(rotation));
    Matrices::setModelMatrix(glm::translate(Matrices::getModelMatrix(), rotationPivot));
    Matrices::setModelMatrix(glm::scale(Matrices::getModelMatrix(), scale));

    switch (shaderProgram) {
        case ShaderPrograms::shaderPrograms::TestProgram:
            TestProgram::draw(vertexData.getID(), numberOfVertices);
            break;
    }
}

void BasicGeometryShape::translate(glm::vec3 distance) {
    position = position + distance;
}

void BasicGeometryShape::scaleUp(glm::vec3 scaleFactor) {
    scale = scale + scaleFactor;
}

void BasicGeometryShape::rotateLocal(glm::quat quaternion) {
    rotation = rotation * quaternion;
}

void BasicGeometryShape::rotateGlobal(glm::quat quaternion) {
    rotation = quaternion * rotation;
}

void BasicGeometryShape::rotateLocal(glm::vec3 eulerAngles) {
    glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
    rotation = rotation * glm::quat(eulerAnglesInRadians);
}

void BasicGeometryShape::rotateGlobal(glm::vec3 eulerAngles) {
    glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
    rotation = glm::quat(eulerAnglesInRadians) * rotation;
}

const glm::quat &BasicGeometryShape::getRotation() const {
    return rotation;
}

const glm::vec3 BasicGeometryShape::getRotation() {
    glm::vec3 eulerAngles = glm::eulerAngles(rotation);
    return glm::vec3(glm::degrees(eulerAngles));
}

void BasicGeometryShape::setRotationLocal(const glm::quat &quaternion) {
    BasicGeometryShape::rotation = quaternion;
}

void BasicGeometryShape::setRotationGlobal(const glm::quat &quaternion) {
    BasicGeometryShape::rotation = quaternion;
}

void BasicGeometryShape::setRotationLocal(const glm::vec3 eulerAngles) {
    glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
    BasicGeometryShape::rotation = glm::quat(eulerAnglesInRadians);
}

void BasicGeometryShape::setRotationGlobal(const glm::vec3 eulerAngles) {
    glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
    BasicGeometryShape::rotation = glm::quat(eulerAnglesInRadians);
}

const glm::vec3 &BasicGeometryShape::getPosition() const {
    return position;
}

void BasicGeometryShape::setPosition(const glm::vec3 &position) {
    BasicGeometryShape::position = position;
}

const glm::vec3 &BasicGeometryShape::getScale() const {
    return scale;
}

void BasicGeometryShape::setScale(const glm::vec3 &scale) {
    BasicGeometryShape::scale = scale;
}

const glm::vec3 &BasicGeometryShape::getRotationPivot() const {
    return rotationPivot;
}

void BasicGeometryShape::setRotationPivot(const glm::vec3 &pivot) {
    BasicGeometryShape::rotationPivot = pivot;
}


const ShaderPrograms::shaderPrograms &BasicGeometryShape::getShaderProgram() const {
    return shaderProgram;
}

void BasicGeometryShape::setShaderProgram(const ShaderPrograms::shaderPrograms &shaderProgram) {
    BasicGeometryShape::shaderProgram = shaderProgram;
}