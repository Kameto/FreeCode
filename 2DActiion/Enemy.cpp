#include "Enemy.hpp"

Enemy::Enemy() 
	: BaseChara()
{
	life = START_LIFE - 4;
	x = 0;
	y = 0;
	bx = 0;
	by = 0;
	speed = 0;
	jspeed = 16.0;
	jflag = false;
	muki = Muki::Right;
	mode = 0;
}

Enemy::Enemy(int _y, int _x, int _mode, int _muki)
	: BaseChara()
{
	life = START_LIFE - 4;
	y = _y;
	x = _x;
	bx = 0;
	by = 0;
	speed = 1.4;
	jspeed = 0.0;
	jflag = false;
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
	jflag = false;
	muki = Muki::Right;
}

void Enemy::Update()
{
	// �ړ�
	BaseChara::Move(false);

	// �s��
	if (mode == 0)
	{
		// �����Ȃ�
	}
	else if (mode == 1)
	{
		BaseChara::JumpMotion(false);
	}
	else {}

	// �d�͏���
	BaseChara::GravtyMotion();

	// �q�b�g����
	BaseChara::HitMotion();
}

void Enemy::Draw()
{
	DrawBox((int)x - 15, (int)y - 15, (int)x + 15, (int)y + 15, 0x00FF00, true);
	DrawFormatString((int)x, (int)y, 0xFF0000, "%d", life);
}

void Enemy::Atack()
{
	// ���̂Ƃ���l���Ă��Ȃ�
}