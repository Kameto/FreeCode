#include "Map.hpp"

std::vector<std::vector<int>>Map::mapdata;
int Map::cameraX;
int Map::cameraY;

Map::Map()
{
	mapdata.resize(32);
	cameraX = 0;
	cameraY = 0;
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
	cameraX = 0;
	cameraY = 0;
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
	std::ifstream ifs;
	std::string path = "", str = "", token = "";
	int x = 0, y = 0;

	path = "map/mapdata.csv";
	ifs.open(path);
	if (ifs)
	{
		while (getline(ifs, str))
		{
			x = 0;
			std::istringstream iss(str);
			while (getline(iss, token, ','))
			{
				Map::mapdata[y].push_back(stoi(token));
			}
			y++;
		}
		x = y = 0;
		path = str = token = "";
		Map::mapdata.shrink_to_fit();
	}
	else {}
	ifs.close();
}