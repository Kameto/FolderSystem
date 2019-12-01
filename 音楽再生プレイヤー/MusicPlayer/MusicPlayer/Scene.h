#pragma once
#include "DeviceManager.h"
#include "Graphics.h"
#include "MusicData.h"
#include <math.h>

class Scene
{
public:
	Scene();
	~Scene();
	void Update();
	void Draw();

private:
	int scrool;
	bool* playFlag;

	template<typename TYPE, size_t SIZE>
	inline const size_t array_length(const TYPE (&array)[SIZE])
	{
		return SIZE;
	}
};