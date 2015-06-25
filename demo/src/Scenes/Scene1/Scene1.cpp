#include "Scene1.h"
#include <SlovanEngine/Core/Renderer/Renderer.h>
#include <SlovanEngine/Core/Constants/Constants.h>

using namespace std;

Scene1::Scene1()
{
	triangle.set(&triangleVertexData, vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
	             vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}, 3);
	plane.set(&planeVertexData, vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
	          vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}, 6);
	cube.set(&cubeVertexData, vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
	         vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}, 36);

	plane.setScale(glm::vec3(0.5f));
	plane.setPosition(glm::vec3(1.5f, 0.0f, 0.0f));
	camera.setPosition(glm::vec3(0.0f, 0.0f, 3.0f));
	cube.setScale(glm::vec3(0.5f));
	cube.setPosition(glm::vec3(0.0f, 0.43f, 0.0f));

	cube.rotateLocal(glm::vec3(0.1f, -45.41f, 54.925f));
}

void Scene1::render()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	GLfloat ratio = (GLfloat) Renderer::getWidth() / (GLfloat) Renderer::getHeight();
	camera.setPerspectiveProjection(45.0f, ratio, 0.1f, 100.0f);
	//camera.setOrthoProjection(-ratio, ratio, -1.0f, 1.0f, 0.1f, 100.0f);

	triangle.draw();
	plane.draw();
	cube.draw();
}

void Scene1::input()
{

}

void Scene1::update()
{
	camera.update();

	cube.rotateGlobal(glm::vec3(0.0f, 1.0f, 0.0f));
}
