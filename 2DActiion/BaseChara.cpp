#include "BaseChara.hpp"

BaseChara::BaseChara()
{
	x = 0.0;
	y = 0.0;
	bx = 0.0;
	by = 0.0;
	speed = 0.0;
	jumpcounter = 0;
	life = 0;
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
	jumpcounter = 0;
	life = 0;
	jumpflag = false;
	muki = Muki::Right;
}

int BaseChara::GetX()
{
	return (int)x;
}

int BaseChara::GetY()
{
	return (int)y;
}

void BaseChara::GravtyMotion()
{
	if (Map::GetMapData(((int)y / TIP_SIZE) + 1, (int)x / TIP_SIZE) != WALL)
	{
		if (!jumpflag)
		{
			y += Gravty;
		}
		else {}
	}
	else
	{
		if (jumpflag)
		{
			jumpflag = false;
		}
	}
}

void BaseChara::JumpMotion()
{
	
}