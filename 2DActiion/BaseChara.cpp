#include "BaseChara.hpp"

BaseChara::BaseChara()
{
	x = 0.0;
	y = 0.0;
	bx = 0.0;
	by = 0.0;
	speed = 0.0;
	jumpspeed = 0.0;
	jumpcounter = 0;
	jumpflag = false;
	muki = Muki::Right;
}

BaseChara::~BaseChara()
{
	x = 0.0;
	y = 0.0;
	bx = 0.0;
	by = 0.0;
	speed = 0.0;
	jumpspeed = 0.0;
	jumpcounter = 0;
	jumpflag = false;
	muki = Muki::Right;
}

bool BaseChara::HitChara()
{
	if (Map::GetMapData((int)y / 32, ((int)x / 32)) == 1 ||
		Map::GetMapData((int)y / 32, ((int)x / 32) + 1) == 1 ||
		Map::GetMapData(((int)y / 32) + 1, (int)x / 32) == 1 )
	{
		return true;
	}
	else 
	{
		return false;
	}
}