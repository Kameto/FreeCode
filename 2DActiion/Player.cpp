#include "Player.hpp"

Player::Player() : BaseChara()
{
	// –³‚µ
}

Player::Player(double _x, double _y) : BaseChara()
{
	x = _x;
	y = _y;
	bx = x;
	by = y;
	speed = 5.2;
}

Player::~Player()
{
	// –³‚µ
}

void Player::Update()
{
	

	if (CheckHitKey(KEY_INPUT_RIGHT) > 0)
	{
		if (Map::GetMapData((int)y / 32, ((int)x / 32) + 1) == 1)
		{
			x += speed;
		}
		else {}
		
	}
	else if (CheckHitKey(KEY_INPUT_LEFT) > 0)
	{
		if (Map::GetMapData((int)y / 32, ((int)x / 32)) == 1)
		{
			x -= speed;
		}
		else {}
	}
	else {}

	if (Map::GetMapData((y / 32) + 1, x / 32) == 1 && !jumpflag)
	{
		y += 2.0;
	}
	else {}


	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		jumpflag = true;
		if (Map::GetMapData((y / 32) - 1, x / 32) == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (jumpflag)
				{
					y -= speed;
				}
				else 
				{
					jumpflag = false;
					break;
				}
			}
		}
		else 
		{
			jumpflag = false;
		}
	}
}

void Player::Draw()
{
	DrawBox(x, y, x + 32, y + 32, 0x00FF00, true);
}