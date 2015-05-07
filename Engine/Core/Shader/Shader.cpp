#include "Shader.h"
#include "../Loggers/Logger.h"

GLuint Shader::compileShader(GLenum type, std::string shaderCode)
{
	GLuint shaderID = glCreateShader(type);

	const char *chShaderCode = shaderCode.c_str();
	glShaderSource(shaderID, 1, &chShaderCode, NULL);
	glCompileShader(shaderID);

#if defined(ADDITIONAL_LOG)
	GLint shaderOK;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &shaderOK);
	if(!shaderOK)
		Logger::printError("Failed compile this shader: " + shaderCode);
#endif

	return shaderID;
}

GLuint Shader::createShaderProgram(std::string vertexShaderCode, std::string fragmentShaderCode)
{
	GLuint vertexShaderID = compileShader(GL_VERTEX_SHADER, vertexShaderCode);
	GLuint fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);

	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

#if defined(ADDITIONAL_LOG)
	GLint programOK;
	glGetProgramiv(programID, GL_COMPILE_STATUS, &programOK);
	if(!programOK)
		Logger::printError("Failed to link shader program");
#endif

	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return programID;
}

void Shader::deleteShaderProgram(GLuint programID)
{
	glDeleteProgram(programID);
}