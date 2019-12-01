#pragma once
#include "DeviceManager.h"
#include "Graphics.h"
#include "PictureData.h"

class Scene
{
public:
	Scene();
	~Scene();
	void Update();
	void Draw();

private:
	int scrool;
};