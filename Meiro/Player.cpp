#include "Player.h"

Player::Player()
{
	x = 0;
	y = 0;
	gr = 0;
	moveFlag = false;
	muki = Muki::NONE;
}

Player::Player(int _y, int _x)
{
	x = 0;
	y = 0;
	gr = 0;
	moveFlag = false;
	muki = Muki::NONE;
	x = _x;
	y = _y;
	gr = LoadGraph("graph/play.png");
}

Player::~Player()
{
	DeleteGraph(gr);
	moveFlag = false;
	muki = Muki::NONE;
	x = 0;
	y = 0;
	gr = 0;
}

void Player::Update()
{
	if (x % 64 == 0 && y % 64 == 0)
	{
		moveFlag = true;
		if (CheckHitKey(KEY_INPUT_UP) == 1)
		{
			muki = Muki::UP;
		}
		else if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		{
			muki = Muki::DOWN;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			muki = Muki::RIGHT;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			muki = Muki::LEFT;
		}
		else
		{
			muki = Muki::NONE;
			moveFlag = false;
		}

		if (!HitArea())
		{
			moveFlag = false;
		}
		else {}
	}

	if (moveFlag)
	{
		switch (muki)
		{
		case Muki::UP:
			y--;
			break;
		case Muki::DOWN:
			y++;
			break;
		case Muki::RIGHT:
			x++;
			break;
		case Muki::LEFT:
			x--;
			break;
		default:
			break;
		}
	}
	else {}
}

void Player::Draw()
{
	DrawGraph(x, y, gr, true);
//#ifdef _DEBUG
//	DrawBox(x * 64, y * 64, x * 64 + 64, y * 64 + 64, 0x0000FF, true);
//	DrawFormatString(x + 32, y + 32, 0x0000FF, "P");
//	DrawFormatString(960, 0, 0xFFFFFF, "x : %d", x);
//	DrawFormatString(960, 16, 0xFFFFFF, "y : %d", y);
//#endif
}

bool Player::HitArea()
{
	if (muki == Muki::UP) { if (Map::GetMapData(y / 64 - 1, x / 64) != 0) { return true; } }
	else if (muki == Muki::DOWN) { if (Map::GetMapData(y / 64 + 1, x / 64) != 0) { return true; } }
	else if (muki == Muki::RIGHT) { if (Map::GetMapData(y / 64, x / 64 + 1) != 0) { return true; } }
	else if (muki == Muki::LEFT) { if (Map::GetMapData(y / 64, x / 64 - 1) != 0) { return true; } }
	else { return false; }
}