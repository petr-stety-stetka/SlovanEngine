void Scene0::render()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	if(i > 120)
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