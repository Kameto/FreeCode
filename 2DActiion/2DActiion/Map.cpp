#include "Map.hpp"

std::vector<std::vector<int>>Map::mapdata;

Map::Map()
{
	mapdata.resize(30);
	comment = "";
	cameraX = 16;
	cameraY = 11;
	LoadText();
}

Map::~Map()
{
	for (int i = 0, n = (unsigned)mapdata.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)mapdata[i].size(); j < m; j++)
		{
			mapdata[i][j] = 0;
		}
	}
	mapdata.erase(mapdata.begin(), mapdata.end());
	comment = "";
}

void Map::Draw()
{
	for (int i = 0, n = (unsigned)mapdata.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)mapdata[i].size(); j < m; j++)
		{
			if (mapdata[i][j] == 0)
			{
				DrawBox(j * 32, i * 32, j * 32 + 32, i * 32 + 32, 0xFFFFFF, true);
			}
			else{}
#ifdef _DEBUG
			DrawFormatString(j * 32, i * 32+16, 0x0000FF, "%d", mapdata[i][j]);
#endif
		}
	}
	DrawFormatString(0, 0, 0xFF0000, "%s", comment.c_str());
}

int Map::GetMapData(int _y, int _x)
{
	return mapdata[_y][_x];
}

void Map::LoadText()
{
	/*
	変換できない形式の文字列が指定された => std::invalid_argument
	範囲外の値が指定された => std::out_of_range
	*/

	std::ifstream ifs;
	std::string path = "", str = "", token = "";
	int x = 0, y = 0, data = 0;

	path = "map/mapdata.csv";
	ifs.open(path);
	if (ifs)
	{
		comment = "safe!";
		while (getline(ifs, str))
		{
			x = 0;
			std::istringstream iss(str);
			while (getline(iss, token, ','))
			{
				mapdata[y].push_back(stoi(token));
			}
			y++;
		}
		x = y = 0;
		path = str = token = "";
		mapdata.shrink_to_fit();
	}
	else
	{
		comment = "error!";
	}
	ifs.close();
}