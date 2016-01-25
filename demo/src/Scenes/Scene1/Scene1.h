#pragma once

#include "../../../../SlovanEngine/Core/Scene/Scene.h"
#include "../../../../SlovanEngine/Core/ShaderPrograms/TestProgram.h"
#include "../../../../SlovanEngine/Core/Objects/GameObjectOld.h"
#include "../../../../SlovanEngine/Core/Cameras/Camera.h"
#include "../../../../SlovanEngine/Core/Objects/GameObject.h"
#include "../../../../SlovanEngine/Core/Cameras/FPSCamera.h"
#include "../../../../SlovanEngine/Core/Cameras/Camera2D.h"

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
			// Back face
			-0.5f, -0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f,
			1.0f, 0.0f, 0.0f,

			// Front face
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

			// Left face
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

			// Right face
			0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, -0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, -0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f,
			1.0f, 1.0f, 0.0f,

			// Bottom face
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

			// Top face
			-0.5f, 0.5f, -0.5f,
			1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f,
			1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f,
			1.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f,
			1.0f, 1.0f, 1.0f};

	GameObjectOld triangle;
	GameObjectOld plane;
	GameObjectOld cube;
	GameObject cube2;
	GameObject nanosuit;
	GameObject createdByPlane;
	GameObject house;
	FPSCamera fpsCamera;
	Camera2D camera2D;

	bool firstMouse = true;
	float lastMouseXPosition, lastMouseYPosition;
	bool drawNanosuit = true;

public:
	Scene1();

	void render() override;

	void update() override;
};
