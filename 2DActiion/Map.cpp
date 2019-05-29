#include "Map.hpp"

std::vector<std::vector<int>>Map::mapdata;
std::string Map::comment;
int Map::cameraX;
int Map::cameraY;

Map::Map()
{
	mapdata.resize(32);
	comment = "";
	cameraX = 16;
	cameraY = 11;
	LoadText();
}

Map::~Map()
{
	for (int i = 0 + cameraY, n = (unsigned)mapdata.size(); i < n; i++)
	{
		for (int j = 0 + cameraX, m = (unsigned)mapdata[i].size(); j < m; j++)
		{
			mapdata[i][j] = 0;
		}
	}
	mapdata.erase(mapdata.begin(), mapdata.end());
	comment = "";
}

void Map::Draw()
{
	// マップスクロールは後回し。わからんｗ

	for (int i = 0, n = (unsigned)mapdata.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)mapdata[i].size(); j < m; j++)
		{
			if (mapdata[i][j] == 0)
			{
				DrawBox(j * 32, i * 32, j * 32 + 32, i * 32 + 32, 0xFFFFFF, true);
				DrawBox(j * 32, i * 32, j * 32 + 32, i * 32 + 32, 0x000000, false);
			}
			else {}
		}
	}
#ifdef _DEBUG
	MapDebugDraw();
#endif
}

int Map::GetMapData(int _y, int _x)
{
	return mapdata[_y][_x];
}

int Map::GetMapSizeX()
{
	return (unsigned)mapdata[0].size();
}

int Map::GetmapSizeY()
{
	return (unsigned)mapdata.size();
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

void Map::MapDebugDraw()
{
	DrawFormatString(0, 0, 0xFF0000, "%s", comment.c_str());
	DrawFormatString(128, 0, 0xFF0000, "Y: %d", (unsigned)mapdata.size());
	DrawFormatString(128, 32, 0xFF0000, "X: %d", (unsigned)mapdata[0].size());
}