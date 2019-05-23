#include "Item.hpp"

Item::Item()
{
	x = 0;
	y = 0;
}

Item::Item(int _y, int _x)
{
	y = _y;
	x = _x;
}

Item::~Item()
{
	x = 0;
	y = 0;
}

void Item::Draw()
{
	DrawCircle(x + 16, y + 16, 10, 0x00FFFF, true, true);
}