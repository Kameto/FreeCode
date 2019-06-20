#include "Player.hpp"

Player::Player() 
	: BaseChara()
{
	life = START_LIFE - 3;
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
	speed = 4.0;
	life = START_LIFE - 3;
	timer = 0;
	ballX = 0;
	ballY = 0;
	atackflag = false;
	b_muki = Muki::None;
}

Player::~Player()
{
	timer = 0;
	ballX = 0;
	ballY = 0;
	atackflag = false;
	b_muki = Muki::None;
}

void Player::Update()
{
	// ジャンプ処理
	BaseChara::JumpMotion(true);

	// 重力処理
	if(!jflag)
	{
		BaseChara::GravtyMotion();
	}

	// 攻撃処理
	Atack();

	// 移動処理
	BaseChara::Move(true);

	// ヒット処理
	BaseChara::HitMotion();
}

void Player::Draw()
{
	if (life <= 5 && life >= 3)
	{
		DrawBox((int)x - 12, (int)y - 12, (int)x + 12, (int)y + 12, 0x00FF00, true);
	}
	else
	{
		DrawBox((int)x - 12, (int)y - 12, (int)x + 12, (int)y + 12, 0x00FF00, true);
	}

	if (atackflag)
	{
		DrawCircle((int)ballX, (int)ballY, 10, 0xFF0000, true, true);
	}
	else {}
}

void Player::Atack()
{
	if ((Keyboard::GetKey(KEY_INPUT_B) == 1 || Joypad::GetPad(XINPUT_BUTTON_B) == 1) && !atackflag)
	{
		atackflag = true;
		if (bc_muki == Muki::Right)
		{
			ballX = x + 64.0;
		}
		else if (bc_muki == Muki::Left)
		{
			ballX = x - 32.0;
		}
		ballY = y;
		b_muki = bc_muki;
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

		if (Map::GetMapData((int)ballY / TIP_SIZE, ((int)ballX / TIP_SIZE)) == 0)
		{
			atackflag = false;
		}
	}
	else 
	{
		ballX = 0;
		ballY = 0;
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