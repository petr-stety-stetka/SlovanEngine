#include "AndroidRenderer.h"
#include "../../../../SlovanEngine/Core/GL/GLHeader.h"
#include "../../../../SlovanEngine/Core/ShaderPrograms/ShaderPrograms.h"
#include "../../../../SlovanEngine/Core/Loggers/Logger.h"
#include <thread>

#define ONE_SECOND 1000000000

FPSLogger AndroidRenderer::fpsLogger;
FPSLogger AndroidRenderer::upsLogger;
std::chrono::nanoseconds::rep AndroidRenderer::nsPerFrameUpdateLoop;
std::chrono::nanoseconds::rep AndroidRenderer::nsPerFrameRenderLoop;

void AndroidRenderer::initialization(short UPS, short FPS) {
    nsPerFrameUpdateLoop = ONE_SECOND / UPS;
    if (FPS > 0)
        nsPerFrameRenderLoop = ONE_SECOND / FPS;

    Renderer::UPS = UPS;
    Renderer::FPS = FPS;

    ShaderPrograms::compileShaderPrograms();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    Renderer::runGameLoop = true;
    fpsLogger.init();
    upsLogger.init();
}

void AndroidRenderer::runLoop() { }

void AndroidRenderer::renderLoop() {
    if (runGameLoop) {
        using namespace std::chrono;
        nanoseconds::rep startTime;
        if (FPS > 0)
            startTime = getActualTimeInNs();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        actualScene->render();

        if (FPS > 0) {
            nanoseconds::rep endTime(getActualTimeInNs());
            nanoseconds::rep updateTime(endTime - startTime);
            nanoseconds::rep sleepTime(nsPerFrameRenderLoop - updateTime);
            nanoseconds::rep nextFrame(startTime + nsPerFrameRenderLoop);

            while (sleepTime > 0 && getActualTimeInNs() + (sleepTime / 1000) < nextFrame) {
                std::this_thread::sleep_for(nanoseconds(sleepTime / 1000));
            }
        }
        fpsLogger.logFrame("FPS");
    }
}

void AndroidRenderer::updateLoop() {
    if (runGameLoop) {
        using namespace std::chrono;
        nanoseconds::rep startTime(getActualTimeInNs());

        actualScene->update();

        nanoseconds::rep endTime(getActualTimeInNs());
        nanoseconds::rep updateTime(endTime - startTime);
        nanoseconds::rep sleepTime(nsPerFrameUpdateLoop - updateTime);
        nanoseconds::rep nextFrame(startTime + nsPerFrameUpdateLoop);

        while (sleepTime > 0 && getActualTimeInNs() + (sleepTime / 1000) < nextFrame) {
            std::this_thread::sleep_for(nanoseconds(sleepTime / 1000));
        }
        upsLogger.logFrame("UPS");
    }
}

std::chrono::nanoseconds::rep AndroidRenderer::getActualTimeInNs() {
    using namespace std::chrono;
    return duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

void AndroidRenderer::terminate() {
    runGameLoop = false;
    delete actualScene;
}

void AndroidRenderer::changeSize(int &width, int &height) {
    glViewport(0, 0, width, height);
    Renderer::width = width;
    Renderer::height = height;
}
