#pragma once
#include <DxLib.h>
#include <string>
#include <vector>

// 画像名の宣言
enum class Picture
{
	NoImage,
	Portion,
	Knife,
	Sword,
	Num
};

typedef struct GraphState
{
	int graph = 0;
	int sizeX = 0;
	int sizeY = 0;
}GS;

class Graphics
{
public:
	Graphics();
	~Graphics();
	static void GraphLoad(const char* path = "graph/");
	static GS GetGraph(const int pName = 0);// 画像情報を取得。デフォはNoImageを表示。
	static const int GetGraphNum();

private:
	static std::vector<GS>graph;
};

typedef Graphics Gra;