#include "../Scenes/Scene0/Scene0.h"
#include <SlovanEngine/PC/Renderer/PCRenderer.h>

int main(int argc, char *argv[])
{
	PCRenderer renderer;
	renderer.initialization(60);
	renderer.createWindow("demo - Slovan Engine", 640, 480, 1);
	Scene *firstScene = new Scene0;

	renderer.setFirstScene(firstScene);
	renderer.runLoop();
	renderer.terminate();
}