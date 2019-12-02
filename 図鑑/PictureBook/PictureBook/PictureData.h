#pragma once
#include "Graphics.h"
#include <fstream>
#include <sstream>
#include <vector>

struct Str
{
	std::string number;					// �}�Ӕԍ�
	std::string name;					// ����
	std::string classification;			// ����
	std::vector<std::string>explanation;// ����
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
	const static int strSize = 4;
};

typedef PictureData PicData;