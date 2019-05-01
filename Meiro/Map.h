#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "DxLib.h"

class Map
{
public:
	Map();
	~Map();

	void Draw();
	static int GetMapData(int _y, int _x);

private:
	static std::vector<std::vector<int>>mapdata;
	int gr[3];

	void SetRoot();
};