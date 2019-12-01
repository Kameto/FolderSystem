#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "MusicData.h"
#include "Macro.h"

class DeviceManager
{
public:
	DeviceManager();
	~DeviceManager();
	void DeviceUpdate();
	static const Keyboard* GetDevKey();
	static const Mouse* GetDevMouse();
private:
	static Keyboard* key;
	static Mouse* mouse;
};

typedef DeviceManager DevMgr;