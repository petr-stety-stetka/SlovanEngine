#include "GameObjectOld.h"
#include "../Shader/Matrices.h"
#include "../../../external/glm/gtc/matrix_transform.hpp"
#include "../../../external/glm/gtx/quaternion.hpp"
#include "../../../external/glm/gtx/euler_angles.hpp"
#include "../ShaderPrograms/TestProgram.h"

GameObjectOld::GameObjectOld() {
    position = glm::vec3(0.0f);
    scale = glm::vec3(1.0f);
    rotationPivot = glm::vec3(0.0f);
}

void GameObjectOld::set(std::vector<GLfloat> *vertices, const ShaderPrograms::shaderPrograms shaderProgram,
                        std::vector<GLuint> attribute, std::vector<GLuint> size, GLuint numberOfVertices) {
    vertexData.set(vertices, attribute, size);
    GameObjectOld::numberOfVertices = numberOfVertices;
    GameObjectOld::shaderProgram = shaderProgram;
}

void GameObjectOld::draw() {
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

void GameObjectOld::translate(glm::vec3 distance) {
    position = position + distance;
}

void GameObjectOld::scaleUp(glm::vec3 scaleFactor) {
    scale = scale + scaleFactor;
}

void GameObjectOld::rotateLocal(glm::quat quaternion) {
    rotation = rotation * quaternion;
}

void GameObjectOld::rotateGlobal(glm::quat quaternion) {
    rotation = quaternion * rotation;
}

void GameObjectOld::rotateLocal(glm::vec3 eulerAngles) {
    glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
    rotation = rotation * glm::quat(eulerAnglesInRadians);
}

void GameObjectOld::rotateGlobal(glm::vec3 eulerAngles) {
    glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
    rotation = glm::quat(eulerAnglesInRadians) * rotation;
}

const glm::quat &GameObjectOld::getRotation() const {
    return rotation;
}

const glm::vec3 GameObjectOld::getRotation() {
    glm::vec3 eulerAngles = glm::eulerAngles(rotation);
    return glm::vec3(glm::degrees(eulerAngles));
}

void GameObjectOld::setRotationLocal(const glm::quat &quaternion) {
    GameObjectOld::rotation = quaternion;
}

void GameObjectOld::setRotationGlobal(const glm::quat &quaternion) {
    GameObjectOld::rotation = quaternion;
}

void GameObjectOld::setRotationLocal(const glm::vec3 eulerAngles) {
    glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
    GameObjectOld::rotation = glm::quat(eulerAnglesInRadians);
}

void GameObjectOld::setRotationGlobal(const glm::vec3 eulerAngles) {
    glm::vec3 eulerAnglesInRadians(glm::radians(eulerAngles));
    GameObjectOld::rotation = glm::quat(eulerAnglesInRadians);
}

const glm::vec3 &GameObjectOld::getPosition() const {
    return position;
}

void GameObjectOld::setPosition(const glm::vec3 &position) {
    GameObjectOld::position = position;
}

const glm::vec3 &GameObjectOld::getScale() const {
    return scale;
}

void GameObjectOld::setScale(const glm::vec3 &scale) {
    GameObjectOld::scale = scale;
}

const glm::vec3 &GameObjectOld::getRotationPivot() const {
    return rotationPivot;
}

void GameObjectOld::setRotationPivot(const glm::vec3 &pivot) {
    GameObjectOld::rotationPivot = pivot;
}


const ShaderPrograms::shaderPrograms &GameObjectOld::getShaderProgram() const {
    return shaderProgram;
}

void GameObjectOld::setShaderProgram(const ShaderPrograms::shaderPrograms &shaderProgram) {
    GameObjectOld::shaderProgram = shaderProgram;
}