#include "PCRenderer.h"
#include "../../ForUse/Loggers/FPSLogger.h"
#include "../../ForUse/Loggers/Logger.h"
#include <iostream>
#include <thread>
#include <sstream>

#define ONE_NANOSECOND 1000000000

GLFWwindow* PCRenderer::window;
short Renderer::UPSandIPS(60);

void PCRenderer::inputLoop()
{
    using namespace std::chrono;

    FPSLogger IPSLogger;
    nanoseconds::rep nsPerFrame(ONE_NANOSECOND / UPSandIPS);

    while(runGameLoop && !glfwWindowShouldClose(window))
    {
        nanoseconds::rep startTime = getActualTimeInNs();

        actualScene->input();

        nanoseconds::rep endTime = getActualTimeInNs();

        nanoseconds::rep updateTime = endTime - startTime;
        nanoseconds::rep sleepTime = nsPerFrame - updateTime;

        nanoseconds::rep nextFrame = startTime + nsPerFrame;

        while(sleepTime > 0 && getActualTimeInNs() + (sleepTime / 100) < nextFrame)
        {
            std::this_thread::sleep_for(nanoseconds(sleepTime / 100));
        }

        IPSLogger.logFrame("IPS");
    }
}

void PCRenderer::updateLoop()
{
    using namespace std::chrono;

    FPSLogger UPSLogger;
    nanoseconds::rep nsPerFrame(ONE_NANOSECOND / UPSandIPS);

    while(runGameLoop && !glfwWindowShouldClose(window))
    {
        nanoseconds::rep startTime = getActualTimeInNs();

        actualScene->update();

        nanoseconds::rep endTime = getActualTimeInNs();

        nanoseconds::rep updateTime = endTime - startTime;
        nanoseconds::rep sleepTime = nsPerFrame - updateTime;

        nanoseconds::rep nextFrame = startTime + nsPerFrame;

        while(sleepTime > 0 && getActualTimeInNs() + (sleepTime/100) < nextFrame)
        {
            std::this_thread::sleep_for(nanoseconds(sleepTime/100));
        }

        UPSLogger.logFrame("UPS");
    }
}

std::chrono::nanoseconds::rep PCRenderer::getActualTimeInNs()
{
    using namespace std::chrono;
    return duration_cast <nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
}


void PCRenderer::renderLoop()
{
    FPSLogger FPSLogger;
    int width, height;
    while(runGameLoop && !glfwWindowShouldClose(window))
    {
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        actualScene->render();

        glfwSwapBuffers(window);
        glfwPollEvents();

        FPSLogger.logFrame("FPS");
    }
}

void PCRenderer::initialization()
{
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
}

void PCRenderer::createWindow(std::string title, int width, int height, int swapInterval)
{
    setVersionOpenGLOnOSX();

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    setWindow(title, swapInterval);
}

void PCRenderer::createWindow(std::string title, int swapInterval)
{
    setVersionOpenGLOnOSX();

    window = glfwCreateWindow(1366, 768, title.c_str(), glfwGetPrimaryMonitor(), NULL);
    setWindow(title, swapInterval);
}

void PCRenderer::setVersionOpenGLOnOSX()
{
#if defined(OS_X)
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif
}

void PCRenderer::setWindow(std::string title, int swapInterval)
{
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowTitle(window, title.c_str());
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();

    std::stringstream renderer, version;
    renderer << glGetString(GL_RENDERER); // Get info about renderer
    version << glGetString(GL_VERSION); // Get info about OpenGL version
    Logger::printInfo("OpenGL renderer: " + renderer.str());
    Logger::printInfo("OpenGL version suppored: " + version.str());

    glfwSwapInterval(swapInterval);
}

void PCRenderer::runLoop()
{
    std::thread tInput(inputLoop);
    std::thread tUpdate(updateLoop);

    renderLoop();

    tInput.join();
    tUpdate.join();
}

void PCRenderer::terminate()
{
    delete actualScene;
    glfwDestroyWindow(window);
    glfwTerminate();
}

void PCRenderer::errorCallback(int error, const char* description)
{
    std::cerr << "Error from GLFW: "<< error << " " << description << std::endl;
}

PCRenderer::PCRenderer()
{

}
