#include "../Scenes/Scene0/Scene0.h"
#include "../../../SlovanEngine/PC/Renderer/PCRenderer.h"

int main(int argc, char *argv[])
{
	PCRenderer renderer;
	/** Enabled can be only one - vSync or FPS! */
	int vSync(0);
	short UPS(60);
	short FPS(60);

	renderer.initialization(UPS, FPS);
	renderer.createWindow("demo - Slovan Engine", 800, 600, vSync);
	//renderer.createWindow("demo - Slovan Engine", vSync);
	Scene *firstScene = new Scene0;

	renderer.setFirstScene(firstScene);
	renderer.runLoop();
	renderer.terminate();

	return 0;
}
