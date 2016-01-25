#pragma once

#include "../../../external/glm/vec3.hpp"

class Camera
{
protected:
    glm::vec3 position;
    glm::vec3 front;

    float scale;
    float scaleMin;
    float scaleMax;

public:
    Camera();

    /**
	 * Set projection matrix. Call this function in render().
	 */
    virtual void render() = 0;

    /**
	 * Update camera position, rotation... Call this function in update().
	 */
    virtual void update() = 0;

    /**
     * Scale up camera by scaleFactor. Call this function in update().
     */
    void scaleUp(float scaleFactor);

    /**
     * Get position.
     */
    const glm::vec3 &getPosition() const;

    /**
     * Set position.
     */
    void setPosition(const glm::vec3 &position);

    /**
     * Get scale.
     */
    float getScale() const;

    /**
     * Set scale.
     */
    void setScale(float scale);

    /**
     * Get minimal scale.
     */
    float getScaleMin() const;

    /**
     * Set minimal scale.
     */
    void setScaleMin(float scaleMin);

    /**
     * Get maximum scale.
     */
    float getScaleMax() const;

    /**
     * Set maximum scale.
     */
    void setScaleMax(float scaleMax);
};