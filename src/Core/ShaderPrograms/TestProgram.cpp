#include "TestProgram.h"
#include "../Shader/Shader.h"

GLuint TestProgram::aVert;
GLuint TestProgram::aColor;
GLuint TestProgram::programID;

void TestProgram::draw(GLuint VAOID, int verticesCount)
{
	glUseProgram(programID);
	glBindVertexArray(VAOID);
	glDrawArrays(GL_TRIANGLES, 0, verticesCount);
	glBindVertexArray(0);
	glUseProgram(0);
}

void TestProgram::compile()
{
	std::string vertexShaderCode("in vec3 aVert;\n"
			                             "in vec3 aColor;\n"
			                             "out vec3 color;\n"
			                             "void main()\n"
			                             "{\n"
			                             "   color = aColor;\n"
			                             "   gl_Position = vec4(aVert.x, aVert.y, aVert.z, 1.0);\n"
			                             "}");
	std::string fragmentShaderCode("out vec4 fragmentColor;\n"
			                               "in vec3 color;\n"
			                               "void main()\n"
			                               "{\n"
			                               "   fragmentColor = vec4(color.x, color.y, color.z, 1.0);\n"
			                               "}");

	programID = Shader::createShaderProgram(vertexShaderCode, fragmentShaderCode);
	aVert = (GLuint) glGetAttribLocation(programID, "aVert");
	aColor = (GLuint) glGetAttribLocation(programID, "aColor");
}

void TestProgram::deleteShaderProgram()
{
	Shader::deleteShaderProgram(programID);
}

GLuint TestProgram::getAVert()
{
	return aVert;
}

GLuint TestProgram::getAColor()
{
	return aColor;
}