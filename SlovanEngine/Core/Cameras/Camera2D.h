#pragma once

#include "Camera.h"

/**
 * 2D (orthographic) camera.
 */
class Camera2D : public Camera {
public:
    /**
     * Create 2D camera (orthographic)
     */
    Camera2D(glm::vec3 position = glm::vec3(0.0f));

    /**
	 * Set projection matrix. Call this function in render().
	 */
    void render() override;

    /**
	 * Update camera position, rotation... Call this function in update().
	 */
    void update() override;

    /**
     * Translate camera up.
     */
    void translateUp(float distance);

    /**
     * Translate camera down.
     */
    void translateDown(float distance);

    /**
     * Translate camera left.
     */
    void translateLeft(float distance);

    /**
     * Translate camera right.
     */
    void translateRight(float distance);
};