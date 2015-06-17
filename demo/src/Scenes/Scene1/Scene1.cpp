#include "Scene1.h"
#include <SlovanEngine/Core/Constants/Constants.h>
#include <SlovanEngine/Core/Shader/Matrices.h>

#define GLM_FORCE_RADIANS

#include <glm/gtc/matrix_transform.hpp>

using namespace std;

Scene1::Scene1()
{
	triangle.set(&triangleVertexData, vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
	             vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}, 3);
	plane.set(&planeVertexData, vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
	          vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}, 6);

}

void Scene1::render()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	triangle.draw();
	plane.draw();
}

void Scene1::input()
{

}

void Scene1::update()
{
	Matrices::setModelMatrix(glm::rotate(Matrices::getModelMatrix(), glm::radians(1.0f), glm::vec3(0.0f, 0.0f, 1.0f)));
	Matrices::setModelMatrix(glm::scale(Matrices::getModelMatrix(), glm::vec3(0.99f, 0.99f, 0.99f)));
}