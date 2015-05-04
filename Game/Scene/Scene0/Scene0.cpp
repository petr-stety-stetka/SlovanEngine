#include "Scene0.h"
#include "../Scene1/Scene1.h"
#include "../../../Engine/ForUse/Renderer/Renderer.h"
#include "../../../Engine/ForUse/GL/GLHeader.h"

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