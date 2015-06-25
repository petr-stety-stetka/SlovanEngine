#pragma once

#include <SlovanEngine/Core/Scene/Scene.h>
#include <SlovanEngine/Core/VertexData/VertexArrayObject.h>
#include <SlovanEngine/Core/ShaderPrograms/TestProgram.h>
#include <SlovanEngine/Core/Objects/GameObject.h>
#include <SlovanEngine/Core/Cameras/Camera.h>

class Scene1 : public Scene
{
private:
	std::vector <GLfloat> triangleVertexData = {0.0f, 0.0f, 0.0f,
	                                            0.0f, 0.0f, 1.0f,
	                                            -0.8f, -0.8f, 0.0f,
	                                            0.0f, 0.0f, 1.0f,
	                                            0.8f, -0.8f, 0.0f,
	                                            0.0f, 0.0f, 1.0f};
	std::vector <GLfloat> planeVertexData = {1.0f, 1.0f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         -1.0f, 1.0f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         -1.0f, -1.0f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         1.0f, 1.0f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         -1.0f, -1.0f, 0.0f,
	                                         0.0f, 1.0f, 0.0f,
	                                         1.0f, -1.0f, 0.0f,
	                                         0.0f, 1.0f, 0.0f};

	std::vector <GLfloat> cubeVertexData = {
			-0.5f, -0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,

			-0.5f, -0.5f, 0.5f,
			0.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f,
			0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f,
			0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f,
			0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f,
			0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f,
			0.0f, 1.0f, 0.0f,

			-0.5f, 0.5f, 0.5f,
			0.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, -0.5f,
			0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,
			0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,
			0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f,
			0.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, 0.5f,
			0.0f, 0.0f, 1.0f,

			0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, -0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, -0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,
			0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f,
			0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f,
			0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f,
			0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, 0.5f,
			0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,
			0.0f, 1.0f, 1.0f,

			-0.5f, 0.5f, -0.5f,
			1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f,
			1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f,
			1.0f, 1.0f, 1.0f};

	GameObject triangle;
	GameObject plane;
	GameObject cube;
	Camera camera;
public:
	Scene1();

	void render() override;

	void input() override;

	void update() override;
};
