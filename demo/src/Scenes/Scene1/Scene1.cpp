Scene1::Scene1() : triangleVertexData {0.0f, 0.0f, 0.0f, -0.8f, -0.8f, 0.0f, 0.8f, -0.8f, 0.0f},
                   planeVertexData {-0.9f, 0.9f, 0.0f, -0.9f, 0.3f, 0.0f, 0.9f, 0.9f, 0.0f,
                                    0.9f, 0.9f, 0.0f, -0.9f, 0.3f, 0.0f, 0.9f, 0.3f, 0.0f},
                   triangleVAO(triangleVertexData, sizeof(triangleVertexData), TestProgram::getAVert()),
                   planeVAO(planeVertexData, sizeof(planeVertexData), TestProgram::getAVert())
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