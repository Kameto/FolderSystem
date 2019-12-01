#include "Mouse.h"

// ボタン
int Mouse::mouse;
int Mouse::button[3];

// 座標
int Mouse::x;
int Mouse::y;

// ホイール
int Mouse::wheel;
double Mouse::wheelNum;

Mouse::Mouse()
{
	mouse = 0;
	for (int i = 0; i < 3; i++)
	{
		button[i] = 0;
	}
	x = 0;
	y = 0;
	wheel = 0;
	wheelNum = 0;
}

Mouse::~Mouse()
{
	mouse = 0;
	for (int i = 0; i < 3; i++)
	{
		button[i] = 0;
	}
	x = 0;
	y = 0;
	wheel = 0;
	wheelNum = 0;
}

void Mouse::Update()
{
	mouse = GetMouseInput();
	wheel = GetMouseWheelRotVol();
	GetMousePoint(&x, &y);

	// 〇〇さんのを参考に
	for (int i = 0; i < 3; i++)
	{
		// 押されていたら
		if ((mouse & 1 << i) == 0)//ボタン数値=> 左 1,右 2,真ん中 4
		{
			if (button[i] < 0)
			{
				button[i] = 0;
			}
			else if(button[i] > 0)
			{
				button[i] = -1;
			}
		}
		else// 押されていたら
		{
			button[i]++;
		}
	}

	// 自作してみた
	/*for (int i = 0; i < 8; i++)
	{
		int inPow = (int)std::pow(2, i);
		if (abs(incode - inPow) == 0)
		{
			buttonNum = i;
		}
	}

	if (mouse & incode)
	{
		button[buttonNum]++;
	}
	else
	{
		button[buttonNum] = 0;
		buttonNum = NULL;
		incode = NULL;
	}*/

	// うまくいかない
	/*for (int i = 0; i < 8; i++)
	{
		int inPow = (int)std::pow(2, i);

		if (abs(incode - inPow) == 0)
		{
			if (mouse & incode)
			{
				button[i]++;
			}
			else
			{
				button[i] = 0;
				incode = NULL;
				buttonNum = NULL;
			}
		}
	}*/


	// ホイール処理
	if (wheel > 0)
	{
		wheelNum += 0.1;
	}
	else if (wheel < 0)
	{
		wheelNum -= 0.1;
	}
	else {}
}

int Mouse::GetMouseX()
{
	return x;
}

int Mouse::GetMouseY()
{
	return y;
}

int& Mouse::GetButton(const CLICK& incode)
{
	return button[static_cast<int>(incode)];
}

double Mouse::GetWheel()
{
	return wheelNum;
}