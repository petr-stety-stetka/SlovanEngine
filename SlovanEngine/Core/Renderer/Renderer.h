#pragma once

#include "../Scene/Scene.h"

class Renderer
{
protected:

	/** Actual scene. */
	static Scene *actualScene;

	/** Can run game loop. */
	static bool runGameLoop;

	/** Update loops (and input loops) per second. */
	static short UPS;

	/** Frames (draws) per second. */
	static short FPS;

	/** Width of window - opengl surface in pixels. */
	static int width;

	/** Height of window - opengl surface in pixels. */
	static int height;

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
	virtual void initialization(short UPSandIPS, short FPS) = 0;

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
	void setFirstScene(Scene *scene);

	/**
	 * Sets the scene to be run first.
	 *
	 * @param scene Pointer to new scene
	 */
	static void loadScene(Scene *scene);

	/**
	 * Get width of window - opengl surface in px.
	 */
	static int getWidth();

	/**
	 * Get height of window - opengl surface in px.
	 */
	static int getHeight();
};