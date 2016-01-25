#include "../../../external/glm/gtc/matrix_transform.hpp"
#include "Camera2D.h"
#include "../Shader/Matrices.h"
#include "../Renderer/Renderer.h"

Camera2D::Camera2D(glm::vec3 position) {
    Camera2D::position = position;
    scaleMin = 0.01f;
    scaleMax = 10.0f;
}

void Camera2D::render() {
    float aspect = (float) Renderer::getWidth() / (float) Renderer::getHeight();
    Matrices::setProjectionMatrix(
            glm::ortho(-aspect * scale, aspect * scale, -1.0f * scale, 1.0f * scale, 0.1f, 100.0f));
}

void Camera2D::update() {
    glm::mat4 matrix;
    matrix *= glm::lookAt(position, position + front, glm::vec3(0.0f, 1.0f, 0.0f));
    Matrices::setViewMatrix(matrix);
}

void Camera2D::translateUp(float distance) {
    position += glm::vec3(0.0f, 1.0f, 0.0f) * distance;
}

void Camera2D::translateDown(float distance) {
    position -= glm::vec3(0.0f, 1.0f, 0.0f) * distance;
}

void Camera2D::translateLeft(float distance) {
    position -= glm::vec3(1.0f, 0.0f, 0.0f) * distance;
}

void Camera2D::translateRight(float distance) {
    position += glm::vec3(1.0f, 0.0f, 0.0f) * distance;
}