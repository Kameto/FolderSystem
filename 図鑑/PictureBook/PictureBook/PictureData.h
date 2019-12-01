#pragma once
#include "Graphics.h"
#include <fstream>
#include <sstream>

struct Str
{
	std::string number;
	std::string name;
	std::string classification;
	std::string Explanation;
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