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

		// �摜�{��
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

		// �O�p�֐���p���ĉ�����{�^�������
		// �{�^���ƃ}�E�X�̋��������߂Ċp�x������o���A
		// �{�^���~�͈̔͂ɓ����Ă�����A�N�V�������N����
	}
}

void Scene::Draw()
{	
	// �ǂݍ��񂾃A�C�e���̕\��
	for (int i = 0, n = PicData::GetDataNum(), j = 0; i < n; i++)
	{
		if (i % 4 == 0) { j = 0; }
		else { j++; }
		DrawRotaGraph(96 + (j * 160), 96 + ((i - j) * 40) - scrool, 0.50, 0.0, Gra::GetGraph().graph, false, false);
		DrawExtendFormatString(96 + (j * 160), 96  + ((i - j) * 40) - scrool, 1.25, 1.25, 0xFF0000, "%d", i + 1);


		if (picFlag[i] == true)
		{
			Str str = PicData::GetPictureData(i);
			DrawExtendFormatString(680, 10, 1.0, 1.0, 0xFFFFFF, "�A�C�e���ԍ�:%s", str.number.c_str());
			DrawExtendFormatString(680, 440, 0.50, 0.50, 0xFFFFFF, "�A�C�e����:%s ����:%s", str.name.c_str(), str.classification.c_str());
			DrawExtendFormatString(680, 480, 0.50, 0.75, 0xFFFFFF, "�����F\n%s", str.Explanation.c_str());
		}
	}

	// DrawExtendFormatString(700, 440, 1.0, 1.0, 0xFFFFFF, "%s\n%s\n%s\n%s", , str.name.c_str(), str.Explanation.c_str(), str.classification.c_str());
}