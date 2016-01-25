#pragma once

#include "Camera.h"

/**
 * FPS (perspective) camera.
 */
class FPSCamera : public Camera {
private:
    glm::vec3 right;

    float yaw;
    float pitch;
    float pitchAngleMax;
    float pitchAngleMin;
    float rotationSensitivity;

public:
    /**
     * Create FPS camera (perspective)
     */
    FPSCamera(glm::vec3 position = glm::vec3(0.0f));

    /**
	 * Set projection matrix. Call this function in render().
	 */

    void render() override;

    /**
	 * Update camera position, rotation... Call this function in update().
	 */
    void update() override;

    /**
     * Translate camera forward.
     */
    void translateForward(float distance);

    /**
     * Translate camera backward.
     */
    void translateBackward(float distance);

    /**
     * Translate camera left.
     */
    void translateLeft(float distance);

    /**
     * Translate camera right.
     */
    void translateRight(float distance);

    /**
     * Translate camera forward-left.
     */
    void translateForwardLeft(float distance);

    /**
     * Translate camera backward-left.
     */
    void translateBackwardLeft(float distance);

    /**
     * Translate camera forward-right.
     */
    void translateForwardRight(float distance);

    /**
     * Translate camera backward-right.
     */
    void translateBackwardRight(float distance);

    /**
     * Translate camera up.
     */
    void translateUp(float distance);

    /**
     * Translate camera down.
     */
    void translateDown(float distance);

    /**
     * Rotate camera by x and y offset.
     */
    void rotate(float x, float y);

    /**
     * Get camera rotation sensitivity.
     */
    float getRotationSensitivity() const;

    /**
     * Set camera rotation sensitivity.
     */
    void setRotationSensitivity(float rotationSensitivity);

    /**
     * Get maximal angle pitch.
     */
    float getPitchAngleMax() const;

    /**
     * Set maximal angle pitch.
     */
    void setPitchAngleMax(float pitchAngleMax);

    /**
     * Get minimal angle pitch.
     */
    float getPitchAngleMin() const;

    /**
     * Set minimal angle pitch.
     */
    void setPitchAngleMin(float pitchAngleMin);
};
