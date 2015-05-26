#include <fstream>
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
		Logger::printError("Failed compile this shader:\n" + shaderCode);
#endif

	return shaderID;
}

std::string Shader::loadShaderSourceCode(std::string file)
{
	std::string sourceCode;
	std::ifstream ifstream(file + ".glsl", std::ifstream::in);

	if(!ifstream)
		Logger::printError("Could not open file: " + file + ".glsl");

	while(ifstream)
	{
		std::string line;
		getline(ifstream, line);
		sourceCode += line + "\n";
	}
	return sourceCode;
}

GLuint Shader::createShaderProgram(std::string vertexShaderCode, std::string fragmentShaderCode)
{
#if defined(PC)
	vertexShaderCode = "#version 120\n" + vertexShaderCode;
	fragmentShaderCode = "#version 120\n" + fragmentShaderCode;
#elif defined(ANDROID)
        vertexShaderCode = "#version 100\n" + vertexShaderCode;
        fragmentShaderCode = "#version 100\n" + "precision mediump float;\n" + fragmentShaderCode;
#endif

	GLuint vertexShaderID = compileShader(GL_VERTEX_SHADER, vertexShaderCode);
	GLuint fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);

	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

#if defined(ADDITIONAL_LOG)
	GLint programOK;
	glGetProgramiv(programID, GL_LINK_STATUS, &programOK);
	if(!programOK)
	{
		Logger::printError("Failed to link shader program, vertex shader code:\n" + vertexShaderCode +
		                   "\nfragmnet shader code:\n" + fragmentShaderCode);
	}
#endif

	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return programID;
}

GLuint Shader::createShaderProgramFromFile(std::string vertexShaderFile, std::string fragmentShaderFile)
{
	std::string vertexShaderCode(loadShaderSourceCode(vertexShaderFile));
	std::string fragmentShaderCode(loadShaderSourceCode(fragmentShaderFile));

	return createShaderProgram(vertexShaderCode, fragmentShaderCode);
}

void Shader::deleteShaderProgram(GLuint programID)
{
	glDeleteProgram(programID);
}