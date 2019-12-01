#include "Scene.h"

Scene::Scene()
{
	scrool = 0;
	const int num = MusData::GetDataNum();
	playFlag = new bool[num];
	for (int i = 0; i < num ; i++)
	{
		playFlag[i] = false;
	}
}

Scene::~Scene()
{
	scrool = 0;
	delete playFlag;
}

void Scene::Update()
{
	scrool = (DevMgr::GetDevMouse()->GetWheel() * 10) * 64;
	if (scrool < 0)
	{
		scrool = 0;
		DevMgr::GetDevMouse()->ResetWheel();
	}


	for (int i = 0, n = MusData::GetDataNum(); i < n; i++)
	{
		// ‰æ‘œ–{‘Ì
		if (abs(DevMgr::GetDevMouse()->GetMouseY() - (i * 192 + 64 - scrool)) < (Gra::GetGraph().sizeY / 4) &&
			abs(DevMgr::GetDevMouse()->GetMouseX() - 96)					  < (Gra::GetGraph().sizeX / 4))
		{
			if (DevMgr::GetDevMouse()->GetButton(CLICK::M_LEFT) == 1)
			{
				DrawExtendFormatString(800, 0, 2.0, 2.0, 0xFFFFFF, "CLICK LEFT");
			}
		}

		auto a = abs(DevMgr::GetDevMouse()->GetMouseY() - (i * 192 + 64 - scrool));
		auto b = abs(DevMgr::GetDevMouse()->GetMouseX() - 980);
		auto c = sqrt((a * a) + (b * b));
		if (c <= 50)
		{
			if (DevMgr::GetDevMouse()->GetButton(CLICK::M_LEFT) == 1)
			{
				if (playFlag[i] == false)
				{
					for (int j = 0; j < n; j++)
					{
						if (playFlag[j] == true)
						{
							playFlag[j] = false;
						}
					}
					playFlag[i] = true;
				}
				else
				{
					playFlag[i] = false;
				}
			}
		}
	}
}

void Scene::Draw()
{	
	DrawGraph(0,0,Gra::GetGraph(Picture::BackImage).graph, true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
	DrawBox(0, 0, 1080, 540, 0xFFFFFF, true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	DrawBox(160, 0, 160 + 8, 1080, 0xFFFFFF, true);
	for (int i = 0, n = MusData::GetDataNum(); i < n; i++)
	{
		DrawRotaGraph(96, i * 192 + 64 - scrool, 0.50, 0.0, Gra::GetGraph().graph, false, false);

		DrawCircle(980, i * 192 + 64 - scrool, 50.0, 0xFFFFFF, true);
		if (playFlag[i] == false)
		{
			DrawTriangle(980 - 16, i * 192 + 64 - 32 - scrool, 
						 980 - 16, i * 192 + 64 + 32 - scrool,	
						 980 + 32, i * 192 + 64 - scrool, 
						  0xFF0000,							true);
		}
		else
		{
			DrawBox(980 - 16, i * 192 + 64 - 16 - scrool, 980 + 16, i * 192 + 64 + 16 - scrool, 0xFF0000, true);
		}

		Str str = MusData::GetMusicData(i);
		DrawFormatString(192, i *192 - scrool, 0x000000, "No.%s\n‹È–¼:%s\n‰ÌŽè:%s", str.number.c_str(), str.music.c_str(), str.singerName.c_str());
	}
}