#pragma once

#include "../../../Engine/ForUse/Objects/Scene.h"

class Scene0 : public Scene
{
public:
	void draw2D() override;

	void draw3D() override;

	void input() override;

	void update() override;
};