#pragma once

#include "../../../../SlovanEngine/Core/Scene/Scene.h"
#include "../../../../SlovanEngine/Core/ShaderPrograms/TestProgram.h"
#include "../../../../SlovanEngine/Core/GraphicModels/BasicGeometryShape.h"
#include "../../../../SlovanEngine/Core/Cameras/Camera.h"
#include "../../../../SlovanEngine/Core/Objects/Model3D.h"
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

	BasicGeometryShape triangle;
	BasicGeometryShape plane;
	BasicGeometryShape cube;
	Model3D cube2;
	Model3D nanosuit;
	Model3D createdByPlane;
	Model3D house;
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
