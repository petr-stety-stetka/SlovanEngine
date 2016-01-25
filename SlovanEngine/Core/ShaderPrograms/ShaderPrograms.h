#pragma once

class ShaderPrograms
{
public:
	/**
	 * Enumeration shader programs.
	 */
	enum class shaderPrograms
	{
		TestProgram,
		AssimpProgram
	};

	/** Compiles shader programs. */
	static void compileShaderPrograms();

	/** Deletes shader programs. */
	static void deleteShaderPrograms();
};