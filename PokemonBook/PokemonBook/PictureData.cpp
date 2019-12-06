#include "PictureData.h"

std::vector<Str>PictureData::pData;
const int PictureData::strSize;

PictureData::PictureData()
{
	pData.resize(0);
}

PictureData::~PictureData()
{
	if (!pData.empty())
	{
		pData.erase(pData.begin(), pData.end());
		pData.shrink_to_fit();
	}
}

void PictureData::LoadPictureData()
{
	std::ifstream ifs;
	std::string str, token;
	ifs.open("datafile/pokemon.csv");
	if (!ifs.fail())
	{
		std::string a[strSize];
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
			newData.number			 = a[0];
			newData.name			 = a[1];
			std::istringstream bufis(a[2]);
			std::string buf = "";
			c = 0;
			while (getline(bufis, buf, '@'))
			{
				newData.racialvalue[c] = buf;
				c++;
			}
			newData.characteristic = a[3];
			std::istringstream bufis2(a[4]);
			buf = "";
			newData.explanation.resize(0);
			while (std::getline(bufis2, buf, '@'))
			{
				newData.explanation.push_back(buf);
			}
			pData.push_back(newData);
		}
	}
}

Str PictureData::GetPictureData(int dataNum)
{
	return pData.at(dataNum);
}

int PictureData::GetDataNum()
{
	return (unsigned)pData.size();
}