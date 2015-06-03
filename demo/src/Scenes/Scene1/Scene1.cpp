#include "Scene1.h"
#include <SlovanEngine/Core/Constants/Constants.h>

using namespace std;

Scene1::Scene1() : triangleVAO(&triangleVertexData, vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
                               vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}),
                   planeVAO(&planeVertexData, vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
                            vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB})
{ }

void Scene1::render()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	TestProgram::draw(triangleVAO.getID(), 3);
	TestProgram::draw(planeVAO.getID(), 6);

}

void Scene1::input()
{

}

void Scene1::update()
{

}