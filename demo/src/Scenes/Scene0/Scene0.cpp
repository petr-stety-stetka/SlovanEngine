#include "Scene0.h"
#include "../Scene1/Scene1.h"
#include <SlovanEngine/Core/Renderer/Renderer.h>

void Scene0::render()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	if(i > 60)
	{
		Scene *newScene1 = new Scene1;
		Renderer::loadScene(newScene1);
	}
	else
		i++;
}

void Scene0::input()
{

}

void Scene0::update()
{
}