#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Str
{
	std::string number;
	std::string music;
	std::string singerName;
};

class MusicData
{
public:
	MusicData();
	~MusicData();
	static void LoadMusicData();
	static Str GetMusicData(const int dataNum);
	static int GetDataNum();

private:
	static std::vector<Str>mData;
	const static int strsize = 3;
};

typedef MusicData MusData;