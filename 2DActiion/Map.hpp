#pragma once
#include "DxLib.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#define TIP_SIZE	32// �}�b�v�`�b�v�̏c���T�C�Y
#define WALL		 0// ��
#define GOAL		 2// �S�[��

class Map
{
public:
	Map();
	~Map();
	static int GetMapData(int _y, int _x);
	static int GetMapSizeX();
	static int GetmapSizeY();
	static void LoadText();

	static int cameraX;
	static int cameraY;

private:
	static std::vector<std::vector<int>>mapdata;
};