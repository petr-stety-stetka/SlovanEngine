#include "Camera.h"

Camera::Camera()
{
    Camera::front = glm::vec3(0.0f, 0.0f, -1.0f);
    scale = 1.0f;
}

void Camera::scaleUp(float scaleFactor)
{
    scale += scaleFactor;
    if (scale < scaleMin)
        scale = scaleMin;
    if (scale > scaleMax)
        scale = scaleMax;
}

const glm::vec3 &Camera::getPosition() const
{
    return position;
}

void Camera::setPosition(const glm::vec3 &position)
{
    Camera::position = position;
}

float Camera::getScale() const
{
    return scale;
}

void Camera::setScale(float scale)
{
    Camera::scale = scale;

    if (scale < scaleMin)
        scale = scaleMin;
    if (scale > scaleMax)
        scale = scaleMax;
}

float Camera::getScaleMin() const {
    return scaleMin;
}

void Camera::setScaleMin(float scaleMin) {
    Camera::scaleMin = scaleMin;
}

float Camera::getScaleMax() const {
    return scaleMax;
}

void Camera::setScaleMax(float scaleMax) {
    Camera::scaleMax = scaleMax;
}