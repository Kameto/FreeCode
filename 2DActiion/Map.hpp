#pragma once
#include "DxLib.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#define TIP_SIZE	32
#define WALL		 0
#define GOAL		 2

class Map
{
public:
	Map();
	~Map();
	void Draw();
	static int GetMapData(int _y, int _x);
	static int GetMapSizeX();
	static int GetmapSizeY();
	static void LoadText();

	static int cameraX;
	static int cameraY;
private:
	void MapDebugDraw();

	static std::vector<std::vector<int>>mapdata;
	static std::string comment;
};