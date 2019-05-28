#pragma once
#include "DxLib.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Map
{
public:
	Map();
	~Map();
	void Draw();
	static int GetMapData(int _y, int _x);

	static int cameraX;
	static int cameraY;

private:
	void LoadText();

	static std::vector<std::vector<int>>mapdata;
	std::string comment;
};