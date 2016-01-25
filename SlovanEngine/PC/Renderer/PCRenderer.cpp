#include "PCRenderer.h"
#include "../../Core/Loggers/FPSLogger.h"
#include "../../Core/Loggers/Logger.h"
#include "../../Core/ShaderPrograms/ShaderPrograms.h"
#include <iostream>
#include <thread>
#include <sstream>

#define ONE_SECOND 1000000000

GLFWwindow *PCRenderer::window;

Keyboard PCRenderer::keyboard;
Mouse PCRenderer::mouse;

void PCRenderer::updateLoop()
{
	using namespace std::chrono;

	FPSLogger UPSLogger;
	nanoseconds::rep nsPerFrame(ONE_SECOND / UPS);

	UPSLogger.init();
	while(runGameLoop && !glfwWindowShouldClose(window))
	{
		nanoseconds::rep startTime(getActualTimeInNs());

		actualScene->update();

		nanoseconds::rep endTime(getActualTimeInNs());

		nanoseconds::rep updateTime(endTime - startTime);
		nanoseconds::rep sleepTime(nsPerFrame - updateTime);

		nanoseconds::rep nextFrame(startTime + nsPerFrame);

		while (sleepTime > 0 && getActualTimeInNs() + (sleepTime / 1000) < nextFrame)
		{
			std::this_thread::sleep_for(nanoseconds(sleepTime / 1000));
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
	using namespace std::chrono;

	FPSLogger FPSLogger;
	nanoseconds::rep nsPerFrame(0);

	if(FPS > 0)
		nsPerFrame = ONE_SECOND / FPS;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	FPSLogger.init();
	while(runGameLoop && !glfwWindowShouldClose(window))
	{
		nanoseconds::rep startTime(0);
		if(FPS > 0)
			startTime = getActualTimeInNs();

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		actualScene->render();

		glfwSwapBuffers(window);
		glfwPollEvents();

		if(FPS > 0)
		{
			nanoseconds::rep endTime(getActualTimeInNs());

			nanoseconds::rep drawTime(endTime - startTime);
			nanoseconds::rep sleepTime(nsPerFrame - drawTime);

			nanoseconds::rep nextFrame(startTime + nsPerFrame);

			while (sleepTime > 0 && getActualTimeInNs() + (sleepTime / 1000) < nextFrame)
			{
				std::this_thread::sleep_for(nanoseconds(sleepTime / 1000));
			}
		}

		FPSLogger.logFrame("FPS");
	}
}

void PCRenderer::initialization(short UPS, short FPS)
{
	glfwSetErrorCallback(errorCallback);

	if(!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	Renderer::UPS = UPS;
	Renderer::FPS = FPS;
}

void PCRenderer::createWindow(std::string title, int width, int height, int swapInterval)
{
	setVersionOfOpenGL();

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	setWindow(title, swapInterval);
	setCallbacks();
	ShaderPrograms::compileShaderPrograms();
}

void PCRenderer::createWindow(std::string title, int swapInterval)
{
	setVersionOfOpenGL();

	window = glfwCreateWindow(1366, 768, title.c_str(), glfwGetPrimaryMonitor(), NULL);
	setWindow(title, swapInterval);
	setCallbacks();
	ShaderPrograms::compileShaderPrograms();
}

void PCRenderer::setVersionOfOpenGL()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if defined(OS_X)
    	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
}

void PCRenderer::setWindow(std::string title, int swapInterval)
{
	if(!window)
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
	Logger::printInfo("OpenGL version supported: " + version.str());

	glfwSwapInterval(swapInterval);
}

void PCRenderer::runLoop()
{
	Renderer::runGameLoop = true;
	std::thread tUpdate(updateLoop);

	renderLoop();
	tUpdate.join();
}

GLFWwindow *PCRenderer::getWindow() {
	return window;
}

void PCRenderer::terminate()
{
	delete actualScene;
	ShaderPrograms::deleteShaderPrograms();
	glfwDestroyWindow(window);
	glfwTerminate();
}

void PCRenderer::errorCallback(int error, const char *description)
{
	Logger::printError("GLFW: " + std::to_string(error) + " " + std::string(description));
}

PCRenderer::PCRenderer()
{

}

void PCRenderer::setCallbacks() {
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mousePositionCallback);
	glfwSetScrollCallback(window, mouseScrollCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetKeyCallback(window, KeyboardCallback);
}

void PCRenderer::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
	mouse.setButtonState(button, action);
}

void PCRenderer::mousePositionCallback(GLFWwindow *window, double xpos, double ypos) {
	mouse.setCursorPosition((float) xpos, (float) ypos);
}

void PCRenderer::mouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
	mouse.setScrollWheel((float) xoffset, (float) yoffset);
}

void PCRenderer::KeyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	keyboard.setKeyState(key, action);
}