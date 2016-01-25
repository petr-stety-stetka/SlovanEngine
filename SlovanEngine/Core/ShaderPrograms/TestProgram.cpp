#include "TestProgram.h"
#include "../Shader/Shader.h"
#include "../Shader/Matrices.h"

#define GLM_FORCE_RADIANS

#include "../../../external/glm/gtc/type_ptr.hpp"

GLuint TestProgram::aVert;
GLuint TestProgram::aColor;
GLuint TestProgram::uMVPMatrix;
GLuint TestProgram::programID;

void TestProgram::draw(GLuint VAOID, int verticesCount)
{
	glUseProgram(programID);
	glBindVertexArray(VAOID);

	Matrices::setMVPMatrix(Matrices::getProjectionMatrix() * Matrices::getViewMatrix() * Matrices::getModelMatrix());
	glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(Matrices::getMVPMatrix()));

	glDrawArrays(GL_TRIANGLES, 0, verticesCount);
	glBindVertexArray(0);
	glUseProgram(0);
}

void TestProgram::compile()
{
	std::string vertexShaderCode("in vec3 aVert;\n"
			                             "in vec3 aColor;\n"
			                             "out vec3 color;\n"
			                             "uniform mat4 uMVPMatrix;\n"
			                             "void main()\n"
			                             "{\n"
			                             "   color = aColor;\n"
			                             "   gl_Position = uMVPMatrix * vec4(aVert, 1.0);\n"
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
	uMVPMatrix = (GLuint) glGetUniformLocation(programID, "uMVPMatrix");
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

GLuint TestProgram::getUMVPMatrix()
{
	return uMVPMatrix;
}