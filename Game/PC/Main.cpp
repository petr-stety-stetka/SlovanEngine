#include "Main.h"
#include "../Scene/Scene0/Scene0.h"
#include "../../Engine/PC/Renderer/PCRenderer.h"

void Main::main(int argc, std::string argv[])
{
	PCRenderer renderer;
	renderer.initialization();
	renderer.createWindow("Slovan Engine", 640, 480, 1);

	Scene *firstScene = new Scene0;

	renderer.setFirstScene(firstScene);
	renderer.runLoop();
	renderer.terminate();
}