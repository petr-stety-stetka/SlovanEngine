#pragma once

#include <SlovanEngine/Core/Scene/Scene.h>
#include <SlovanEngine/Core/Data/VertexArrayObject.h>
#include <SlovanEngine/Core/ShaderPrograms/TestProgram.h>
#include <string>

class Scene1 : public Scene
{
private:
	GLfloat triangleVertexData[9];
	GLfloat planeVertexData[18];
	VertexArrayObject triangleVAO;
	VertexArrayObject planeVAO;
public:
	Scene1();

	void render() override;

	void input() override;

	void update() override;
};
