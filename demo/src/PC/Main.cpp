int main(int argc, char *argv[])
{
	PCRenderer renderer;
	renderer.initialization();
	renderer.createWindow("demo - Slovan Engine", 640, 480, 1);
	Scene *firstScene = new Scene0;

	renderer.setFirstScene(firstScene);
	renderer.runLoop();
	renderer.terminate();
}