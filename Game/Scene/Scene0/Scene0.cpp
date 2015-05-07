#include "Scene0.h"
#include "../Scene1/Scene1.h"
#include "../../../Engine/Core/GL/GLHeader.h"
#include "../../../Engine/Core/Renderer/Renderer.h"

void Scene0::render()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

void Scene0::input()
{

}

void Scene0::update()
{
	Scene *newScene1 = new Scene1;
	Renderer::loadScene(newScene1);
}