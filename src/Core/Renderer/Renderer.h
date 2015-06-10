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
	static short UPSandIPS;

	/** Compiles default shader programs. */
	void compileDefaultShaderPrograms();

	/** Deletes default shader programs. */
	void deleteDefaultShaderPrograms();

public:
	/**
	 * Initialization renderer.
	 * The first method that should be called.
	 *
	 * @param UPSandIPS Are update loops (and input loops) per second.
	 *                  Recommended value is 60 or 30.
	 */
	virtual void initialization(short UPSandIPS) = 0;

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
};