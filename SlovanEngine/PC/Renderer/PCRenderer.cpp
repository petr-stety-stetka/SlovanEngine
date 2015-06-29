#include "PCRenderer.h"
#include "../../Core/Loggers/FPSLogger.h"
#include "../../Core/Loggers/Logger.h"
#include "../../Core/ShaderPrograms/ShaderPrograms.h"
#include <iostream>
#include <thread>
#include <sstream>

#define ONE_SECOND 1000000000

GLFWwindow *PCRenderer::window;
short Renderer::UPSandIPS(0);
short Renderer::FPS(0);

void PCRenderer::inputLoop()
{
	using namespace std::chrono;

	FPSLogger IPSLogger;
	nanoseconds::rep nsPerFrame(ONE_SECOND / UPSandIPS);

	while(runGameLoop && !glfwWindowShouldClose(window))
	{
		nanoseconds::rep startTime(getActualTimeInNs());

		actualScene->input();

		nanoseconds::rep endTime(getActualTimeInNs());

		nanoseconds::rep inputTime(endTime - startTime);
		nanoseconds::rep sleepTime(nsPerFrame - inputTime);

		nanoseconds::rep nextFrame(startTime + nsPerFrame);

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
	nanoseconds::rep nsPerFrame(ONE_SECOND / UPSandIPS);

	while(runGameLoop && !glfwWindowShouldClose(window))
	{
		nanoseconds::rep startTime(getActualTimeInNs());

		actualScene->update();

		nanoseconds::rep endTime(getActualTimeInNs());

		nanoseconds::rep updateTime(endTime - startTime);
		nanoseconds::rep sleepTime(nsPerFrame - updateTime);

		nanoseconds::rep nextFrame(startTime + nsPerFrame);

		while(sleepTime > 0 && getActualTimeInNs() + (sleepTime / 100) < nextFrame)
		{
			std::this_thread::sleep_for(nanoseconds(sleepTime / 100));
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
	nanoseconds::rep nsPerFrame;

	if(FPS > 0)
		nsPerFrame = ONE_SECOND / FPS;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	while(runGameLoop && !glfwWindowShouldClose(window))
	{
		nanoseconds::rep startTime;
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

			while(sleepTime > 0 && getActualTimeInNs() + (sleepTime / 100) < nextFrame)
			{
				std::this_thread::sleep_for(nanoseconds(sleepTime / 100));
			}
		}

		FPSLogger.logFrame("FPS");
	}
}

void PCRenderer::initialization(short UPSandIPS, short FPS)
{
	glfwSetErrorCallback(errorCallback);

	if(!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	Renderer::UPSandIPS = UPSandIPS;
	Renderer::FPS = FPS;
}

void PCRenderer::createWindow(std::string title, int width, int height, int swapInterval)
{
	setVersionOfOpenGL();

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	setWindow(title, swapInterval);
	ShaderPrograms::compileShaderPrograms();
}

void PCRenderer::createWindow(std::string title, int swapInterval)
{
	setVersionOfOpenGL();

	window = glfwCreateWindow(1366, 768, title.c_str(), glfwGetPrimaryMonitor(), NULL);
	setWindow(title, swapInterval);
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
	ShaderPrograms::deleteShaderPrograms();
	glfwDestroyWindow(window);
	glfwTerminate();
}

void PCRenderer::errorCallback(int error, const char *description)
{
	std::cerr << "Error from GLFW: " << error << " " << description << std::endl;
}

PCRenderer::PCRenderer()
{

}
