#pragma once
#include "Graphics.h"
#include <fstream>
#include <sstream>
#include <vector>

struct Str
{
	std::string number;					// �}�Ӕԍ�
	std::string name;					// ���O
	std::string racialvalue[7];			// �푰�l
	std::string characteristic;			// ����
	std::vector<std::string>explanation;// ��������
};

class PictureData
{
public:
	PictureData();
	~PictureData();
	static void LoadPictureData();
	static Str GetPictureData(int dataNum);
	static int GetDataNum();

private:
	static std::vector<Str>pData;// �i���o�[�A���O�A���ށA����
	const static int strSize = 5;
};

typedef PictureData PicData;