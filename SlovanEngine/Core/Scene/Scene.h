#pragma once

#if defined(PC)

#include "../GL/GLHeader.h"

#endif

class Scene
{
protected:

#if defined(PC)
	GLFWwindow *window;
#endif

public:
	/** Function for rendering graphics */
	virtual void render() = 0;

	/** Function for update game states and physics */
	virtual void update() = 0;

	virtual ~Scene()
	{ };
};