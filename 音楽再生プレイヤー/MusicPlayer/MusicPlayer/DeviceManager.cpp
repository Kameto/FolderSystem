#include "DeviceManager.h"

Keyboard* DeviceManager::key;
Mouse* DeviceManager::mouse;

DeviceManager::DeviceManager()
{
	this->key = new Keyboard();
	this->mouse = new Mouse();
}

DeviceManager::~DeviceManager()
{
	RELEASE(this->key);
	RELEASE(this->mouse);
}

void DeviceManager::DeviceUpdate()
{
	key->KeyUpdate();
	mouse->Update();
}

const Keyboard* DeviceManager::GetDevKey()
{
	return key;
}

const Mouse* DeviceManager::GetDevMouse()
{
	return mouse;
}