#pragma once

#include <string>
#include "../GL/GLHeader.h"

class Shader
{
private:
	static GLuint compileShader(GLenum type, std::string shaderCode);

public:
	static GLuint createShaderProgram(std::string vertexShaderCode, std::string fragmentShaderCode);

	static void deleteShaderProgram(GLuint programID);
};