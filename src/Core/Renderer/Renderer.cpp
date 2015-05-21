#include "Renderer.h"
#include "../ShaderPrograms/TestProgram.h"

Scene *Renderer::actualScene = nullptr;

bool Renderer::runGameLoop(true);

void Renderer::setFirstScene(Scene *scene)
{
	loadScene(scene);
}

void Renderer::loadScene(Scene *scene)
{
	delete actualScene;
	actualScene = scene;
}

void Renderer::compileDefaultShaderPrograms()
{
	TestProgram::compile();
}

void Renderer::deleteDefaultShaderPrograms()
{
	TestProgram::deleteShaderProgram();
}