#pragma once

#include "../../ForUse/Objects/Scene.h"

class Renderer
{
protected:

    /**
     * Actual scene.
     */
    static Scene* actualScene;

    /**
     * Can run game loop.
     */
    static bool runGameLoop;

public:
    /**
     * Initialization renderer.
     * The first method that should be called.
     */
    virtual void initialization() = 0;

    /**
     * Run game loop.
     */
    virtual void runLoop() = 0;

    /**
     * Terminate renderer.
     * The last method that should be called.
     */
    virtual void terminate() = 0;

    /**
     * Sets the scene to be run first.
     *
     * @param scene Pointer to new scene
     */
    void setFirstScene(Scene* scene);

    /**
     * Sets the scene to be run first.
     *
     * @param scene Pointer to new scene
     */
    static void loadScene(Scene* scene);
};