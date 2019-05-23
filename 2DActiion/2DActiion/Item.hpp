#pragma once
#include "DxLib.h"
class Item
{
public:
	Item();
	Item(int _y, int _x);
	~Item();
	void Draw();

	int x;
	int y;
};