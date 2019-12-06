#pragma once
#include "Graphics.h"
#include <fstream>
#include <sstream>
#include <vector>

struct Str
{
	std::string number;					// 図鑑番号
	std::string name;					// 名前
	std::string racialvalue[7];			// 種族値
	std::string characteristic;			// 特性
	std::vector<std::string>explanation;// 特性説明
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
	const static int strSize = 5;
};

typedef PictureData PicData;