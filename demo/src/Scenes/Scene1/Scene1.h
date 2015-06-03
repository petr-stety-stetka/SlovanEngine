#pragma once

#include <SlovanEngine/Core/Scene/Scene.h>
#include <SlovanEngine/Core/VertexData/VertexArrayObject.h>
#include <SlovanEngine/Core/ShaderPrograms/TestProgram.h>
#include <string>

class Scene1 : public Scene
{
private:
	std::vector <GLfloat> triangleVertexData = {0.0f, 0.0f, 0.0f,
	                                            0.0f, 0.0f, 1.0f,
	                                            -0.8f, -0.8f, 0.0f,
	                                            0.0f, 0.0f, 1.0f,
	                                            0.8f, -0.8f, 0.0f,
	                                            0.0f, 0.0f, 1.0f};
	std::vector <GLfloat> planeVertexData = {-0.9f, 0.9f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         -0.9f, 0.3f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         0.9f, 0.9f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         0.9f, 0.9f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         -0.9f, 0.3f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         0.9f, 0.3f, 0.0f,
	                                         0.0f, 1.0f, 0.0f};
	VertexArrayObject triangleVAO;
	VertexArrayObject planeVAO;
public:
	Scene1();

	void render() override;

	void input() override;

	void update() override;
};
