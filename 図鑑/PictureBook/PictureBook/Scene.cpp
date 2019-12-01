#include "Scene.h"

Scene::Scene()
{
	scrool = 0;
}

Scene::~Scene()
{
	scrool = 0;
}

void Scene::Update()
{
	scrool = (DevMgr::GetDevMouse()->GetWheel() * 10) * 64;

	for (int i = 0, n = PicData::GetDataNum(); i < n; i++)
	{
		// 画像本体
		if (abs(DevMgr::GetDevMouse()->GetMouseY() - (i * 192 + 64 - scrool)) < (Gra::GetGraph().sizeY / 4) &&
			abs(DevMgr::GetDevMouse()->GetMouseX() - 96)					  < (Gra::GetGraph().sizeX / 4))
		{
			if (DevMgr::GetDevMouse()->GetButton(CLICK::M_LEFT) == 1)
			{
				DrawExtendFormatString(800, 0, 2.0, 2.0, 0xFFFFFF, "CLICK LEFT");
			}
		}

		// 三角関数を用いて押せるボタンを作る
		// ボタンとマウスの距離を求めて角度を割り出し、
		// ボタン円の範囲に入っていたらアクションを起こす
	}
}

void Scene::Draw()
{	
	DrawBox(160, 0, 160 + 8, 1080, 0xFFFFFF, true);
	for (int i = 0, n = PicData::GetDataNum(); i < n; i++)
	{
		DrawRotaGraph(96, i * 192 + 64 - scrool, 0.50, 0.0, Gra::GetGraph().graph, false, false);
		DrawExtendFormatString(96, i * 192 + 96 - scrool, 1.0, 1.0, 0xFF0000, "No.%d", i + 1);

		Str str = PicData::GetPictureData(i);
		DrawFormatString(192, i *192 - scrool, 0xFFFFFF, "No.%s\nName:%s\nClass:%s\nEx:%s", str.number.c_str(), str.name.c_str(), str.classification.c_str(), str.Explanation.c_str());
	}

	DrawBox(DevMgr::GetDevMouse()->GetMouseX() - 16, DevMgr::GetDevMouse()->GetMouseY() - 16, 
			DevMgr::GetDevMouse()->GetMouseX() + 16, DevMgr::GetDevMouse()->GetMouseY() + 16, 
										   0xFF0000,									true);
}