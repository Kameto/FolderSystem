#pragma once
#include <DxLib.h>
#include <string>
#include <vector>

// 画像名の宣言
enum class Picture
{
	NoImage,
	Portion,
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
	static GS GetGraph(const Picture pName = Picture::NoImage);// 画像情報を取得。デフォはNoImageを表示。

private:
	static std::vector<GS>graph;
};

typedef Graphics Gra;