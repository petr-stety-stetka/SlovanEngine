#include "../../../external/glm/detail/func_trigonometric.hpp"
#include "../../../external/glm/gtc/matrix_transform.hpp"
#include "FPSCamera.h"
#include "../Shader/Matrices.h"
#include "../Renderer/Renderer.h"
#include "../Loggers/Logger.h"

#define ROTATION_SENSITIVITY 0.0025

FPSCamera::FPSCamera(glm::vec3 position) {
    FPSCamera::position = position;
    right = glm::vec3(1.0f, 0.0f, 0.0f);
    scaleMin = 1.0f;
    scaleMax = 5.0f;

    yaw = 0.0f;
    pitch = 0.0f;
    pitchAngleMax = 90.0f;
    pitchAngleMin = -90.0f;
    rotationSensitivity = 1.0f;
}

void FPSCamera::render() {
    float aspect = (float) Renderer::getWidth() / (float) Renderer::getHeight();
    Matrices::setProjectionMatrix(glm::perspective(glm::radians(45 / scale), aspect, 0.1f, 100.0f));
}

void FPSCamera::update() {
    float cosPitch = glm::cos(pitch);
    float sinPitch = glm::sin(pitch);
    float cosYaw = glm::cos(yaw);
    float sinYaw = glm::sin(yaw);

    front.z = cosYaw * cosPitch;
    front.x = sinYaw * cosPitch;

    right = -glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 matrix = {glm::vec4(cosYaw, sinYaw * sinPitch, sinYaw * cosPitch, 0),
                        glm::vec4(0, cosPitch, -sinPitch, 0),
                        glm::vec4(-sinYaw, cosYaw * sinPitch, cosPitch * cosYaw, 0),
                        glm::vec4(-glm::dot(glm::vec3(cosYaw, 0, -sinYaw), position),
                                  -glm::dot(glm::vec3(sinYaw * sinPitch, cosPitch, cosYaw * sinPitch), position),
                                  -glm::dot(glm::vec3(sinYaw * cosPitch, -sinPitch, cosPitch * cosYaw), position),
                                  1)
    };

    Matrices::setViewMatrix(matrix);
}

void FPSCamera::translateForward(float distance) {
    position -= front * distance;
}

void FPSCamera::translateBackward(float distance) {
    position += front * distance;
}

void FPSCamera::translateLeft(float distance) {
    position -= right * distance;
}

void FPSCamera::translateRight(float distance) {
    position += right * distance;
}

void FPSCamera::translateForwardLeft(float distance) {
    distance = distance / sqrtf(2);
    position -= front * distance;
    position -= right * distance;
}

void FPSCamera::translateBackwardLeft(float distance) {
    distance = distance / sqrtf(2);
    position += front * distance;
    position -= right * distance;
}

void FPSCamera::translateForwardRight(float distance) {
    distance = distance / sqrtf(2);
    position -= front * distance;
    position += right * distance;
}

void FPSCamera::translateBackwardRight(float distance) {
    distance = distance / sqrtf(2);
    position += front * distance;
    position += right * distance;
}

void FPSCamera::translateUp(float distance) {
    position += glm::vec3(0.0f, 1.0f, 0.0f) * distance;
}

void FPSCamera::translateDown(float distance) {
    position -= glm::vec3(0.0f, 1.0f, 0.0f) * distance;
}

void FPSCamera::rotate(float x, float y) {
    yaw += (-x * rotationSensitivity * ROTATION_SENSITIVITY);
    pitch += (y * rotationSensitivity * ROTATION_SENSITIVITY);

    float pitchMax = 0.016666667f * pitchAngleMax;
    float pitchMin = 0.016666667f * pitchAngleMin;
    if (pitch > pitchMax)
        pitch = pitchMax;
    if (pitch < pitchMin)
        pitch = pitchMin;
}

float FPSCamera::getRotationSensitivity() const {
    return rotationSensitivity;
}

void FPSCamera::setRotationSensitivity(float rotationSensitivity) {
    FPSCamera::rotationSensitivity = rotationSensitivity;
}

float FPSCamera::getPitchAngleMax() const {
    return pitchAngleMax;
}

void FPSCamera::setPitchAngleMax(float pitchAngleMax) {
    FPSCamera::pitchAngleMax = pitchAngleMax;
}

float FPSCamera::getPitchAngleMin() const {
    return pitchAngleMin;
}

void FPSCamera::setPitchAngleMin(float pitchAngleMin) {
    FPSCamera::pitchAngleMin = pitchAngleMin;
}