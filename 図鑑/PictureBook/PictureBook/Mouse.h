#pragma once
#include <DxLib.h>
#include <cmath>

/*
MOUSE_INPUT_LEFT	0x0001(MOUSE_INPUT_1)		  1
MOUSE_INPUT_RIGHT	0x0002(MOUSE_INPUT_2)		  2
MOUSE_INPUT_MIDDLE	0x0004(MOUSE_INPUT_3)		  4
MOUSE_INPUT_4		0x0008						  8
MOUSE_INPUT_5		0x0010						 16
MOUSE_INPUT_6		0x0020						 32
MOUSE_INPUT_7		0x0040					 	 64
MOUSE_INPUT_8		0x0080						128


※重複しているとしたの処理が優先されるため注意
if(Mouse::GetButton(MOUSE_INPUT_LEFT) > 0){}
if(Mouse::GetButton(MOUSE_INPUT_RIGHT) > 0){}
*/

enum class CLICK { M_LEFT, M_RIGHT, M_MIDDLE };

class Mouse
{
public:
	Mouse();
	~Mouse();
	static void Update();
	static int& GetButton(const CLICK& incode);
	static double GetWheel();
	static int GetMouseX();
	static int GetMouseY();
	
private:
	
	static int mouse;
	static int button[3];

	/*static int pushButton[8];
	static int unpushButton[8];*/
	
	// カーソル
	static int x;
	static int y;

	// ホイール
	static int wheel;
	static double wheelNum;
	
};