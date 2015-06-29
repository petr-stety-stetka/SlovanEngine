#pragma once

class Scene
{
protected:

public:
	/** Function for rendering graphics */
	virtual void render() = 0;

	/** Function for processing input events */
	virtual void input() = 0;

	/** Function for update game states and physics */
	virtual void update() = 0;

	virtual ~Scene()
	{ };
};