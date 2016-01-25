#include "ShaderPrograms.h"
#include "AssimpProgram.h"
#include "TestProgram.h"

void ShaderPrograms::compileShaderPrograms()
{
	TestProgram::compile();
	AssimpProgram::compile();
}

void ShaderPrograms::deleteShaderPrograms()
{
	TestProgram::deleteShaderProgram();
	AssimpProgram::deleteShaderProgram();
}