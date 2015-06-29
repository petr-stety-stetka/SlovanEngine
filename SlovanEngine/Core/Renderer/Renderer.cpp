#include "Renderer.h"

Scene *Renderer::actualScene = nullptr;

bool Renderer::runGameLoop(true);

int Renderer::width = 0;
int Renderer::height = 0;

void Renderer::setFirstScene(Scene *scene)
{
	loadScene(scene);
}

void Renderer::loadScene(Scene *scene)
{
	delete actualScene;
	actualScene = scene;
}

int Renderer::getWidth()
{
	return width;
}

int Renderer::getHeight()
{
	return height;
}