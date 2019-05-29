#include "Player.hpp"

Player::Player() 
	: BaseChara()
{
	life = START_LIFE;
	timer = 0;
	ballX = 0;
	ballY = 0;
	atackflag = false;
	b_muki = Muki::Right;
}

Player::Player(double _x, double _y) 
	: BaseChara()
{
	x = _x;
	y = _y;
	bx = x;
	by = y;
	speed = 4.2;
	life = START_LIFE;
	timer = 0;
	ballX = 0;
	ballY = 0;
	atackflag = false;
	b_muki = Muki::Right;
}

Player::~Player()
{
	timer = 0;
	ballX = 0;
	ballY = 0;
	atackflag = false;
	b_muki = Muki::Right;
}

void Player::Update()
{	
	if (CheckHitKey(KEY_INPUT_RIGHT) > 0)
	{
		muki = Muki::Right;
		x += speed;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT) > 0)
	{
		muki = Muki::Left;
		x -= speed;
	}
	else {}

	BaseChara::GravtyMotion();
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && !jumpflag)
	{
		BaseChara::JumpMotion();
	}
	Atack();
}

void Player::Draw()
{
	DrawBox((int)x, (int)y, (int)x + 32, (int)y + 32, 0x00FF00, true);

	if (atackflag)
	{
		DrawCircle(ballX, ballY, 10, 0xFF0000, true, true);
	}
	else {}
}

void Player::Atack()
{
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		atackflag = true;
		if (muki == Muki::Right)
		{
			ballX = x + 64;
			ballY = y + 16;
			b_muki = Muki::Right;
		}
		else if (muki == Muki::Left)
		{
			ballX = x - 32;
			ballY = y + 16;
			b_muki = Muki::Left;
		}
		else {}
	}

	if (atackflag)
	{
		if (b_muki == Muki::Right)
		{
			ballX += speed;
		}
		else if (b_muki == Muki::Left)
		{
			ballX -= speed;
		}
		else {}

		if (Map::GetMapData(ballY / TIP_SIZE, ballX / TIP_SIZE) == 0 ||
			Map::GetMapData(ballY / TIP_SIZE, (ballX / TIP_SIZE) + 1) == 0)
		{
			atackflag = false;
		}
	}
}

int Player::GetBX()
{
	return (int)ballX;
}

int Player::GetBY()
{
	return (int)ballY;
}