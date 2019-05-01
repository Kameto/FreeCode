#include "Map.h"

std::vector<std::vector<int>> Map::mapdata;

Map::Map()
{
	mapdata.resize(10);
	for (int i = 0, n = (unsigned)mapdata.size(); i < n; i++)
	{
		mapdata[i].resize(10);
	}
	for (int i = 0, n = (unsigned)mapdata.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)mapdata[i].size(); j < m; j++)
		{
			mapdata[i][j] = 0;
		}
	}
	SetRoot();

	gr[0] = 0;
	gr[1] = 0;
	gr[2] = 0;
	gr[0] = LoadGraph("graph/floor.png");
	gr[1] = LoadGraph("graph/wall.png");
	gr[2] = LoadGraph("graph/exit.png");
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
	DeleteGraph(gr[0]);
	DeleteGraph(gr[1]);
	DeleteGraph(gr[2]);
	gr[0] = 0;
	gr[1] = 0;
	gr[2] = 0;
}

void Map::Draw()
{
	for (int i = 0, n = (unsigned)mapdata.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)mapdata[i].size(); j < m; j++)
		{
			DrawGraph(j * 64, i * 64, gr[mapdata[i][j]], true);

//#ifdef _DEBUG
//			DrawBox(j * 64, i * 64, j * 64 + 64, i * 64 + 64, 0xFF0000, false);
//			DrawFormatString(j * 64, i * 64, 0x000000, "%d - %d", i, j);
//			DrawFormatString(j * 64, i * 64 + 16, 0x000000, "%d", mapdata[i][j]);
//#endif
		}
	}
}

int Map::GetMapData(int _y, int _x)
{
	return mapdata[_y][_x];
}

void Map::SetRoot()
{
	for (int i = 1, n = (unsigned)mapdata.size() - 1; i < n; i++)
	{
		mapdata[i][1] = 1;
		mapdata[i][(unsigned)mapdata[0].size() - 2] = 1;
	}
	for (int i = 1, n = (unsigned)mapdata[0].size() - 1; i < n; i++)
	{
		mapdata[1][i] = 1;
	}
	mapdata[(unsigned)mapdata.size() - 1][1] = 2;
}