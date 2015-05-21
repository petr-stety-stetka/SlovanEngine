#pragma once

#include <string>
#include "../GL/GLHeader.h"

class Shader
{
private:
	static GLuint compileShader(GLenum type, std::string shaderCode);

public:
	/**
	 * Create shader program and return ID of program.
	 */
	static GLuint createShaderProgram(std::string vertexShaderCode, std::string fragmentShaderCode);

	/**
	 * Delete shader program.
	 */
	static void deleteShaderProgram(GLuint programID);
};