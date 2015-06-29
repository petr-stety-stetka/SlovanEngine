#pragma once

#include "TestProgram.h"

class ShaderPrograms
{
public:
	/**
	 * Enumeration shader programs.
	 */
	enum class shaderPrograms
	{
		TestProgram
	};

	/** Compiles shader programs. */
	static void compileShaderPrograms();

	/** Deletes shader programs. */
	static void deleteShaderPrograms();
};