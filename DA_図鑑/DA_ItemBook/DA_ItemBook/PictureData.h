#pragma once
#include "Graphics.h"
#include <fstream>
#include <sstream>
#include <vector>

struct Str
{
	std::string number;					// 図鑑番号
	std::string name;					// 名称
	std::string classification;			// 分類
	std::vector<std::string>explanation;// 説明
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
	static std::vector<Str>pData;// ナンバー、名前、分類、説明
	const static int strSize = 4;
};

typedef PictureData PicData;