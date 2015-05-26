#include "TestProgram.h"
#include "../Shader/Shader.h"

GLint TestProgram::aVert;
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
	std::string vertexShaderCode("attribute vec3 vert;\n"
			                             "void main()\n"
			                             "{\n"
			                             "   gl_Position = vec4(vert.x, vert.y, vert.z, 1.0);\n"
			                             "}");
	std::string fragmentShaderCode("void main()\n"
			                               "{\n"
			                               "   gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
			                               "}");

	programID = Shader::createShaderProgram(vertexShaderCode, fragmentShaderCode);
	aVert = glGetAttribLocation(programID, "vert");
}

void TestProgram::deleteShaderProgram()
{
	Shader::deleteShaderProgram(programID);
}

GLint TestProgram::getAVert()
{
	return aVert;
}