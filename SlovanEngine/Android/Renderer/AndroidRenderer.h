#pragma once

#include "../../../../SlovanEngine/Core/Renderer/Renderer.h"
#include "../../../../SlovanEngine/Core/Loggers/FPSLogger.h"
#include <chrono>


class AndroidRenderer : public Renderer {
private:
    static FPSLogger fpsLogger;
    static FPSLogger upsLogger;
    static std::chrono::nanoseconds::rep nsPerFrameUpdateLoop;
    static std::chrono::nanoseconds::rep nsPerFrameRenderLoop;

    /**
    * Return actual time in nanoseconds by std::chrono::high_resolution_clock.
    */
    static std::chrono::nanoseconds::rep getActualTimeInNs();

public:

    /**
     * Initialization renderer.
     * The first method that should be called.
     */
    void initialization(short UPS, short FPS) override;

    /**
     * Does not apply to Android.
     * See renderLoop() and updateLoop().
     */
    void runLoop() override;

    /**
     * Render loop for drawing objects.
     */
    static void renderLoop();

    /**
     * Update loop for updating status (position, rotation...) of objects.
     */
    static void updateLoop();

    /**
     * Terminate renderer.
     * The last method that should be called.
     */
    void terminate() override;

    /**
     * Change viewport for OpenGL.
     */
    void changeSize(int &width, int &height);
};
