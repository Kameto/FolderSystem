#include "Mouse.h"

// �{�^��
int Mouse::mouse;
int Mouse::button[3];

// ���W
int Mouse::x;
int Mouse::y;

// �z�C�[��
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

	// �Z�Z����̂��Q�l��
	for (int i = 0; i < 3; i++)
	{
		// ������Ă�����
		if ((mouse & 1 << i) == 0)//�{�^�����l=> �� 1,�E 2,�^�� 4
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
		else// ������Ă�����
		{
			button[i]++;
		}
	}

	// ���삵�Ă݂�
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

	// ���܂������Ȃ�
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


	// �z�C�[������
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