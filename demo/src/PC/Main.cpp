#include "../Scenes/Scene0/Scene0.h"
#include "../../../SlovanEngine/PC/Renderer/PCRenderer.h"

int main(int argc, char *argv[])
{
	PCRenderer renderer;
	/** Enabled can be only one - vSync or FPS! */
	int vSync(1);
	short UPSandIPS(60);
	short FPS(0);

	renderer.initialization(UPSandIPS, FPS);
	renderer.createWindow("demo - Slovan Engine", 640, 480, vSync);
	Scene *firstScene = new Scene0;

	renderer.setFirstScene(firstScene);
	renderer.runLoop();
	renderer.terminate();

	return 0;
}