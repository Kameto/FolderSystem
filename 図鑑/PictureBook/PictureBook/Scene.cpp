#include "Scene.h"

Scene::Scene()
{
	scrool = 0;
	const int num = PicData::GetDataNum();
	picFlag = new bool[num];
	for (int i = 0; i < num; i++)
	{
		picFlag[i] = false;
	}
}

Scene::~Scene()
{
	scrool = 0;
	delete[] picFlag;
}

void Scene::Update()
{
	scrool = (DevMgr::GetDevMouse()->GetWheel() * 10) * 64;
	if (scrool < 0)
	{
		scrool = 0;
		DevMgr::GetDevMouse()->ResetWheel(true);
	}
	else if(scrool > (PicData::GetDataNum() / 4) * 96)
	{
		DevMgr::GetDevMouse()->ResetWheel(false);
		scrool = (DevMgr::GetDevMouse()->GetWheel() * 10) * 64;
	}

	for (int i = 0, n = PicData::GetDataNum(), j = 0; i < n; i++)
	{
		if (i % 4 == 0) { j = 0; }
		else { j++; }

		if (abs(DevMgr::GetDevMouse()->GetMouseY() - (96 + ((i - j) * 40) - scrool)) < (Gra::GetGraph().sizeY / 4) &&
			abs(DevMgr::GetDevMouse()->GetMouseX() - (96 + (j * 160))) < (Gra::GetGraph().sizeX / 4))
		{
			if (DevMgr::GetDevMouse()->GetButton(CLICK::M_LEFT) == 1)
			{
				if (picFlag[i] == false)
				{
					for (int k = 0; k < n; k++)
					{
						if (picFlag[k] == true)
						{
							picFlag[k] = false;
						}
					}
					picFlag[i] = true;
				}
				else
				{
					picFlag[i] = false;
				}
			}
		}

		// 画像本体
		/*if (abs(DevMgr::GetDevMouse()->GetMouseY() - (i * 192 + 64 - scrool)) < (Gra::GetGraph().sizeY / 4) &&
			abs(DevMgr::GetDevMouse()->GetMouseX() - 96)					  < (Gra::GetGraph().sizeX / 4))
		{
			if (DevMgr::GetDevMouse()->GetButton(CLICK::M_LEFT) == 1)
			{
				if (picFlag[i] == false)
				{
					for (int j = 0; j < n; j++)
					{
						if (picFlag[j] == true)
						{
							picFlag[j] = false;
						}
					}
					picFlag[i] = true;
				}
				else
				{
					picFlag[i] = false;
				}
			}
		}*/

		// 三角関数を用いて押せるボタンを作る
		// ボタンとマウスの距離を求めて角度を割り出し、
		// ボタン円の範囲に入っていたらアクションを起こす
	}
}

void Scene::Draw()
{	
	// 背景色
	DrawBox(0, 0, 1080, 640, 0x98fb98, true);

	// 縦線
	DrawBox(0, 0, 16, 640, 0x8B0000, true);
	DrawBox(0, 0, 16, 640, 0x000000, false);
	DrawBox(656, 0, 672, 640, 0x800000, true);
	DrawBox(656, 0, 672, 640, 0x000000, false);
	
	// 横線
	DrawBox(0, 0 - scrool, 672, 16 - scrool, 0x8B0000, true);
	DrawBox(0, 0 - scrool, 672, 16 - scrool, 0x000000, false);
	DrawBox(0, ((PicData::GetDataNum() - 4) * 64) - scrool, 672, ((PicData::GetDataNum() - 4) * 64) + 16 - scrool, 0x800000, true);
	DrawBox(0, ((PicData::GetDataNum() - 4) * 64) - scrool, 672, ((PicData::GetDataNum() - 4) * 64) + 16 - scrool, 0x000000, false);

	// 読み込んだアイテムの表示
	for (int i = 0, n = PicData::GetDataNum(), j = 0; i < n; i++)
	{
		if (i % 4 == 0) { j = 0; }
		else { j++; }
		if (i < Gra::GetGraphNum())
		{
			if (Gra::GetGraph(i).graph != 0)
			{
				DrawRotaGraph(96 + (j * 160), 96 + ((i - j) * 40) - scrool, 0.50, 0.0, Gra::GetGraph(i).graph, false, false);
			}
			else
			{
				DrawRotaGraph(96 + (j * 160), 96 + ((i - j) * 40) - scrool, 0.50, 0.0, Gra::GetGraph().graph, false, false);
			}
		}
		else
		{
			DrawRotaGraph(96 + (j * 160), 96 + ((i - j) * 40) - scrool, 0.50, 0.0, Gra::GetGraph().graph, false, false);
		}
		DrawExtendFormatString(96 + (j * 160), 96  + ((i - j) * 40) - scrool, 1.25, 1.25, 0xFF0000, "%d", i + 1);

		if (picFlag[i] == true)
		{
			// 説明枠組み
			DrawBox(675, 5, 1065, 45, 0xFFFFFF, true);
			DrawBox(675, 435, 1065, 475, 0xFFFFFF, true);
			DrawBox(675, 475, 1065, 630, 0xFFFFFF, true);
			DrawExtendFormatString(680, 480, 1.0, 1.0, 0x000000, "説明：");

			// 情報本体
			Str str = PicData::GetPictureData(i);
			DrawExtendFormatString(680, 10, 1.0, 1.0, 0x000000, "  %s", str.name.c_str());
			DrawExtendFormatString(680, 440, 0.70, 0.70, 0x000000, "アイテム番号:%s 分類:%s", str.number.c_str(), str.classification.c_str());
			for (int j = 0, m = (unsigned)str.explanation.size(); j < m; j++)
			{
				DrawExtendFormatString(680, 512 + (j * 32), 0.55, 1.0, 0x000000, "%s", str.explanation.at(j).c_str());
			}
		}
	}

	// DrawExtendFormatString(700, 440, 1.0, 1.0, 0xFFFFFF, "%s\n%s\n%s\n%s", , str.name.c_str(), str.Explanation.c_str(), str.classification.c_str());
}