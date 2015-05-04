#pragma once

#include "../../../Engine/ForUse/Objects/Scene.h"

class Scene0 : public Scene
{
public:
	void render() override;

	void input() override;

	void update() override;
};