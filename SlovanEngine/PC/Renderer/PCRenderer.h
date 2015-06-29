#pragma once

#include "../../Core/GL/GLHeader.h"
#include <string>
#include <chrono>
#include "../../Core/Renderer/Renderer.h"

class PCRenderer : public Renderer
{
private:

	/**
	 * GLFW Window.
	 */
	static GLFWwindow *window;

	/**
	 * Set Window title and swap interval.
	 *
	 * @param title Title window.
	 * @param swapInterval Minimum number of screen updates to wait for until the buffers are swapped.
	 */
	void setWindow(std::string title, int swapInterval);

	/**
	 * Error callback to GLFW.
	 */
	static void errorCallback(int error, const char *description);

	/**
	 * Input loop for all input. Here you mustn't call OpenGL function!
	 */
	static void inputLoop();

	/**
	 * Update loop for update state objects. Here you mustn't call OpenGL function!
	 */
	static void updateLoop();

	/**
	 * render loop for draw. Only here you can call OpenGL functions!
	 */
	static void renderLoop();


	/**
	 * Return actual time in nanoseconds by std::chrono::high_resolution_clock.
	 */
	static std::chrono::nanoseconds::rep getActualTimeInNs();


	/** Set the required version of OpenGL*/
	void setVersionOfOpenGL();

public:

	/**
	 * Initialization renderer.
	 * The first method that should be called.
	 *
	 * @param UPSandIPS Are update loops (and input loops) per second.
	 *                  Recommended value is 60 or 30.
	 * @param FPS Frames per second. If this is 0, then FPS is unlimited or limited by VSync On/Off.
	 *            If this is greater than 0, then FPS is limited on this value.
	 *            If is VSync enabled, FPS must be 0!
	 */
	void initialization(short UPSandIPS, short FPS) override;

	/**
	 * Create new fullscreen window.
	 *
	 * @param title Title window.
	 * @param swapInterval Minimum number of screen updates to wait for until the buffers are swapped.
	 *                     If this is 1 VSync is enabled, if is 0 VSync is disabled.
	 *                     If is VSync enabled, FPS must be 0!
	 */
	void createWindow(std::string title, int swapInterval);

	/**
	 * Create new window with specified size.
	 *
	 * @param title Title window.
	 * @param width Width of window in screen coordinates (mostly px).
	 * @param height Height of window in screen coordinates (mostly px).
	 * @param swapInterval Minimum number of screen updates to wait for until the buffers are swapped.
	 *                     If this is 1 VSync is enabled, if this is 0 VSync is disabled.
	 *                     If is VSync enabled, FPS must be 0!
	 */
	void createWindow(std::string title, int width, int height, int swapInterval);

	/**
	 * Run game loop.
	 */
	void runLoop() override;

	/**
	 * Terminate renderer.
	 * The last method that should be called.
	 */
	void terminate() override;

	PCRenderer();
};