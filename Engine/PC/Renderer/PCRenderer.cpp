#include "PCRenderer.h"
#include "../../ForUse/Loggers/FPSLogger.h"
#include <iostream>
#include <thread>

GLFWwindow* PCRenderer::window;

void PCRenderer::inputLoop()
{
    while(runGameLoop && !glfwWindowShouldClose(window))
        actualScene->input();
}

void PCRenderer::updateLoop()
{
    using namespace std::chrono;

    //TODO: 2. version 30 UPS and 60 UPS
    FPSLogger UPSLogger;

    while(runGameLoop && !glfwWindowShouldClose(window))
    {
        nanoseconds::rep startTime = getActualTimeInNs();

        actualScene->update();

        nanoseconds::rep endTime = getActualTimeInNs();

        nanoseconds::rep updateTime = endTime - startTime;
        nanoseconds::rep sleepTime = 16666666 - updateTime; //+- 60 UPS

        nanoseconds::rep nextFrame = startTime + 16666666;

        while(sleepTime > 0 && getActualTimeInNs() + (sleepTime/100) < nextFrame)
        {
            std::this_thread::sleep_for(nanoseconds(sleepTime/100));
        }
        /* Or this
        if(sleepTime > 0)
        {
            std::this_thread::sleep_for(std::chrono::nanoseconds(sleepTime));
        }*/

        UPSLogger.logFrame("UPS");
    }
}

std::chrono::nanoseconds::rep PCRenderer::getActualTimeInNs()
{
    using namespace std::chrono;
    return duration_cast <nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
}


void PCRenderer::drawLoop()
{
    int width, height;
    while(runGameLoop && !glfwWindowShouldClose(window))
    {
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        actualScene->draw2D();
        actualScene->draw3D();

        glfwSwapBuffers(window);
        glfwPollEvents();
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
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    setWindow(title, swapInterval);
}

void PCRenderer::createWindow(std::string title, int swapInterval)
{
    window = glfwCreateWindow(1366, 768, title.c_str(), glfwGetPrimaryMonitor(), NULL);
    setWindow(title, swapInterval);
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
    glfwSwapInterval(swapInterval);
}

void PCRenderer::runLoop()
{
    std::thread tInput(inputLoop);
    std::thread tUpdate(updateLoop);

    drawLoop();

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
