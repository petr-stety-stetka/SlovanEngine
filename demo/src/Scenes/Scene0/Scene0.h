#pragma once

#include "../../../../SlovanEngine/Core/Scene/Scene.h"

class Scene0 : public Scene
{
private:
	int i = 0;
public:
	void render() override;

	void input() override;

	void update() override;
};