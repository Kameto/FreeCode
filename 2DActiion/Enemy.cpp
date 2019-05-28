#include "Enemy.hpp"

Enemy::Enemy() 
	: BaseChara()
{
	x = 0;
	y = 0;
	bx = 0;
	by = 0;
	speed = 0;
	jumpflag = false;
	muki = Muki::Right;
	mode = 0;
}

Enemy::Enemy(int _y, int _x, int _mode, int _muki)
	: BaseChara()
{
	y = _y;
	x = _x;
	bx = 0;
	by = 0;
	speed = 1.4;
	jumpflag = false;
	if (muki == 0)
	{
		muki = Muki::Right;
	}
	else
	{
		muki = Muki::Left;
	}
	mode = _mode;
}

Enemy::~Enemy()
{
	x = 0;
	y = 0;
	bx = 0;
	by = 0;
	speed = 0;
	jumpflag = false;
	muki = Muki::Right;
}

void Enemy::Update()
{
	if (Map::GetMapData((int)y / 32, ((int)x / 32) + 1) == 0 && muki == Muki::Right)
	{
		muki = Muki::Left;
	}
	else if (Map::GetMapData((int)y / 32, (int)x / 32) == 0 && muki == Muki::Left)
	{
		muki = Muki::Right;
	}
	else {}

	switch (muki)
	{
	case Muki::Left:
		x += speed;
		break;
	case Muki::Right:
		x -= speed;
		break;
	default:
		break;
	}
	
	if (mode == 0)
	{
		// ‰½‚à‚È‚µ
	}
	else if (mode == 1)
	{
		// ƒWƒƒƒ“ƒv‚³‚¹‚é‚Ì‚Ý
	}
	else {}
	
	if (Map::GetMapData(((int)y / 32) + 1, (int)x / 32) == 1 && !jumpflag)
	{
		y += 5.0;
	}
	else {}
}

void Enemy::Draw()
{
	DrawBox((int)x, (int)y, (int)x + 32, (int)y + 32, 0x00FF00, true);
}