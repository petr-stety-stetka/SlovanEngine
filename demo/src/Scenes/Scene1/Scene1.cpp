#include <istream>
#include "../../../../external/glm/gtc/type_ptr.hpp"
#include "Scene1.h"
#include "../../../../SlovanEngine/Core/Constants/Constants.h"
#include "../../../../SlovanEngine/PC/Input/Keyboard.h"
#include "../../../../SlovanEngine/PC/Input/Mouse.h"

using namespace std;

Scene1::Scene1()
{
	triangle.set(&triangleVertexData, ShaderPrograms::shaderPrograms::TestProgram,
	             vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
	             vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}, 3);
	plane.set(&planeVertexData, ShaderPrograms::shaderPrograms::TestProgram,
	          vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
	          vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}, 6);
	cube.set(&cubeVertexData, ShaderPrograms::shaderPrograms::TestProgram,
	         vector <GLuint>{TestProgram::getAVert(), TestProgram::getAColor()},
	         vector <GLuint>{Constants::POSITION_3D, Constants::COLOR_RGB}, 36);

	plane.setScale(glm::vec3(0.5f));
	plane.setPosition(glm::vec3(1.5f, 0.0f, 0.0f));
	fpsCamera.setPosition(glm::vec3(0.0f, 0.0f, 3.0f));
	//camera2D.setPosition(glm::vec3(0.0f, 0.0f, 3.0f));
	cube.setScale(glm::vec3(0.5f));
	cube.setPosition(glm::vec3(0.0f, 0.43f, 0.0f));

	cube.rotateLocal(glm::vec3(0.1f, -45.41f, 54.925f));

	cube2.setModel("cube.fbx");
	cube2.setPosition(glm::vec3(0.0f, 0.0f, -5.0f));
	cube2.setRotationGlobal(glm::vec3(0.0f, 45.0f, 0.0f));
	cube2.rotateGlobal(glm::vec3(0.0f, 0.0f, 45.0f));

	nanosuit.setModel("nanosuit.fbx");
	nanosuit.setPosition(glm::vec3(0.0f, -1.75f, 0.0f));
	nanosuit.setScale(glm::vec3(0.2f, 0.2f, 0.2f));

	house.setModel("house1.fbx");
	house.setScale(glm::vec3(0.01f));
	house.translate(glm::vec3(5.0f, 0.0f, 0.0f));

	createdByPlane.setModel("CreatedByPlane.fbx");
	createdByPlane.translate(glm::vec3(-2.0f, 0.0f, 0.0f));
}

void Scene1::render()
{
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	fpsCamera.render();
	//camera2D.render();

	//triangle.draw();
	plane.draw();
	//cube.draw();
	createdByPlane.draw();

	//Wiredframe
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (drawNanosuit)
		nanosuit.draw();
	house.draw();
	cube2.draw();
}

void Scene1::update()
{
	float camRotateX, camRotateY;

	if ((Keyboard::isRepeated(KEY_W) && Keyboard::isRepeated(KEY_A)) ||
		(Keyboard::isRepeated(KEY_W) && Keyboard::isRepeated(KEY_D)) ||
		(Keyboard::isRepeated(KEY_S) && Keyboard::isRepeated(KEY_A)) ||
		(Keyboard::isRepeated(KEY_S) && Keyboard::isRepeated(KEY_D))) {
		if (Keyboard::isRepeated(KEY_W) && Keyboard::isRepeated(KEY_A))
			fpsCamera.translateForwardLeft(0.1f);
		if (Keyboard::isRepeated(KEY_W) && Keyboard::isRepeated(KEY_D))
			fpsCamera.translateForwardRight(0.1f);
		if (Keyboard::isRepeated(KEY_S) && Keyboard::isRepeated(KEY_A))
			fpsCamera.translateBackwardLeft(0.1f);
		if (Keyboard::isRepeated(KEY_S) && Keyboard::isRepeated(KEY_D))
			fpsCamera.translateBackwardRight(0.1f);
	}
	else {
		if (Keyboard::isRepeated(KEY_W))
			fpsCamera.translateForward(0.1f);
		if (Keyboard::isRepeated(KEY_S))
			fpsCamera.translateBackward(0.1f);
		if (Keyboard::isRepeated(KEY_A))
			fpsCamera.translateLeft(0.1f);
		if (Keyboard::isRepeated(KEY_D))
			fpsCamera.translateRight(0.1f);
	}
	if (Keyboard::isRepeated(KEY_LEFT_SHIFT))
		fpsCamera.translateUp(0.05f);
	if (Keyboard::isRepeated(KEY_LEFT_CONTROL))
		fpsCamera.translateDown(0.05f);

	/* // camera2D
	if(Keyboard::isRepeated(KEY_UP))
		camera2D.translateUp(0.1f);
	if(Keyboard::isRepeated(KEY_DOWN))
		camera2D.translateDown(0.1f);
	if(Keyboard::isRepeated(KEY_LEFT))
		camera2D.translateLeft(0.1f);
	if(Keyboard::isRepeated(KEY_RIGHT))
		camera2D.translateRight(0.1f);
	 */

	if (Mouse::isReleased(MOUSE_BUTTON_LEFT))
		drawNanosuit = !drawNanosuit;
	if (Mouse::isPressed(MOUSE_BUTTON_MIDDLE))
		fpsCamera.setScale(1.0f);

	fpsCamera.scaleUp(Mouse::getYScrollWheel() * 0.1f);

	//camera2D.scaleUp(Mouse::getYScrollWheel()*0.1f);

	float mouseXPosition = Mouse::getXCursorPosition();
	float mouseYPosition = Mouse::getYCursorPosition();

	if (firstMouse) {
		lastMouseXPosition = mouseXPosition;
		lastMouseYPosition = mouseYPosition;
		firstMouse = false;
	}

	camRotateX = mouseXPosition - lastMouseXPosition;
	camRotateY = lastMouseYPosition - mouseYPosition;

	lastMouseXPosition = mouseXPosition;
	lastMouseYPosition = mouseYPosition;

	fpsCamera.rotate(camRotateX, camRotateY);
	fpsCamera.update();

	//camera2D.update();

	cube.rotateGlobal(glm::vec3(0.0f, 1.0f, 0.0f));
	nanosuit.rotateGlobal(glm::vec3(0.0f, 1.0f, 0.0f));
	cube2.rotateGlobal(glm::vec3(0.0f, 1.0f, 0.0f));
}
