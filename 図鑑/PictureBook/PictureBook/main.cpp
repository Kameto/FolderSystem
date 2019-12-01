#include <DxLib.h>
#include "Scene.h"
#include "Macro.h"
#include "DeviceManager.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	SetWindowText("�}�ӃV�X�e��");
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(1080, 640, 32);
	SetFontSize(32);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)
	{
		return -1;
	}
	Graphics* gra = new Graphics();
	gra->GraphLoad();
	PictureData* pd = new PictureData();
	pd->LoadPictureData();
	DeviceManager* dmgr = new DeviceManager();
	Scene* sc = new Scene();


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		sc->Update();
		sc->Draw();
		dmgr->DeviceUpdate();
		if (dmgr->GetDevKey()->GetKey(KEY_INPUT_END) == 1)
		{
			break;
		}
		ScreenFlip();
	}
	RELEASE(sc);
	RELEASE(dmgr);
	RELEASE(pd);
	RELEASE(gra);
	InitGraph();
	DxLib_End();

	return 0;
}