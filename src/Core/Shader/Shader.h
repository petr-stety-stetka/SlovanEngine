#pragma once

#include <string>
#include "../GL/GLHeader.h"

class Shader
{
private:
	static GLuint compileShader(GLenum type, std::string shaderCode);

	static std::string loadShaderSourceCode(std::string file);

public:

	/**
	 * Create shader program and return ID of program.
	 */
	static GLuint createShaderProgram(std::string vertexShaderCode, std::string fragmentShaderCode);

	/**
	 * Create shader program from file and return ID of program.
	 */
	static GLuint createShaderProgramFromFile(std::string vertexShaderFile, std::string fragmentShaderFile);

	/**
	 * Delete shader program.
	 */
	static void deleteShaderProgram(GLuint programID);
};