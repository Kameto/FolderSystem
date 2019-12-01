#pragma once
#include <DxLib.h>
#include <string>
#include <vector>

// �摜���̐錾
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
	static GS GetGraph(const Picture pName = Picture::NoImage);// �摜�����擾�B�f�t�H��NoImage��\���B

private:
	static std::vector<GS>graph;
};

typedef Graphics Gra;