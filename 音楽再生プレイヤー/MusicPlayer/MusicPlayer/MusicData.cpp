#include "MusicData.h"

std::vector<Str>MusicData::mData;
const int MusicData::strsize;

MusicData::MusicData()
{
	mData.resize(0);
}

MusicData::~MusicData()
{
	if (!mData.empty())
	{
		mData.erase(mData.begin(), mData.end());
	}
}

void MusicData::LoadMusicData()
{
	std::ifstream ifs;
	std::string str, token;
	ifs.open("datafile/musicdata.csv");
	if (!ifs.fail())
	{
		std::string a[strsize];
		Str newData;
		int c = 0;
		while (getline(ifs, str))
		{
			std::istringstream iss(str);
			c = 0;
			while (getline(iss, token, ','))
			{
				a[c] = token;
				c++;
			}
			newData.number = a[0];
			newData.music = a[1];
			newData.singerName = a[2];
			mData.push_back(newData);
		}
	}
}

Str MusicData::GetMusicData(const int dataNum)
{
	return mData.at(dataNum);
}

int MusicData::GetDataNum()
{
	return (unsigned)mData.size();
}