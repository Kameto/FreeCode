#include "BaseChara.hpp"

BaseChara::BaseChara()
{
	// ��{���i
	x		 = 0;
	y		 = 0;
	bx		 = 0.0;
	by		 = 0.0;
	speed	 = 0.0;
	life	 = 0;
	hitflag	 = false;
	muki	 = Muki::None;
	bc_muki	 = Muki::None;

	// �W�����v�֘A
	jy		 = 0.0;
	jcy		 = 0.0;
	jspeed	 = 0.0;
	jcounter = 0;
	jflag	 = false;
	actflag	 = false;

	// ���̑�
	timer	 = 0;
}

BaseChara::~BaseChara()
{
	// ��{���i
	x			= 0;
	y			= 0;
	bx			= 0.0;
	by			= 0.0;
	speed		= 0.0;
	life		= 0;
	hitflag		= false;
	muki		= Muki::None;
	bc_muki		= Muki::None;

	// �W�����v�֘A
	jy			= 0.0;
	jspeed		= 0.0;
	jcounter	= 0;
	jflag		= false;
	actflag		= false;

	// ���̑�
	timer		= 0;
}

int BaseChara::GetX()
{
	return (int)x;
}

int BaseChara::GetY()
{
	return (int)y;
}

int BaseChara::GetSpeed()
{
	return (int)speed;
}

void BaseChara::Move(bool cflag)
{
	if (cflag)
	{
		// �v���C���[�̍s������
		if (Keyboard::GetKey(KEY_INPUT_RIGHT) > 0
			|| Joypad::GetPad(XINPUT_BUTTON_DPAD_RIGHT) > 0)
		{
			muki = bc_muki = Muki::Right;
		}
		else if (Keyboard::GetKey(KEY_INPUT_LEFT) > 0
			|| Joypad::GetPad(XINPUT_BUTTON_DPAD_LEFT) > 0)
		{
			muki = bc_muki = Muki::Left;
		}
		else 
		{
			muki = Muki::None;
		}
	}
	else
	{
		// �G�̍s������
		if (Map::GetMapData((int)y / 32, (int)((x + (Camera::c_moverX) / 2) - 16) / 32) == 0)
		{
			muki = bc_muki = Muki::Right;
		}
		else if (Map::GetMapData((int)y / 32, (int)((x + (Camera::c_moverX) / 2) + 16) / 32) == 0)
		{
			muki = bc_muki = Muki::Left;
		}
		else {}

		if (muki == Muki::None)
		{
			if (bc_muki == Muki::Right)
			{
				x = x - 4;
				muki = Muki::Left;
			}
			else if (bc_muki == Muki::Left)
			{
				x = x + 4;
				muki = Muki::Right;
			}
		}
	}

	// �ړ�����
	if (SideHitArea() == false)
	{
		muki = Muki::None;
	}
	else {}

	// �ړ�����
	switch (muki)
	{
	case Muki::Right:
		x += speed;
		break;
	case Muki::Left:
		x -= speed;
		break;
	case Muki::None:
		break;
	default:
		break;
	}

	// ���W�L��
	if ((int)x % 32 == 0)
	{
		x = (int)x;
	}

	if ((int)y % 4 == 0)
	{
		y = (int)y;
	}
}

// �d�͏���
void BaseChara::GravtyMotion()
{
	if (Map::GetMapData((int)(y + 14) / 32, (int)((x + (Camera::c_moverX) / 2) - 14) / 32) != 0
	 && Map::GetMapData((int)(y + 14) / 32, (int)((x + (Camera::c_moverX) / 2) + 14) / 32) != 0)
	{
		y += Gravty;
	}
}

// �W�����v����
void BaseChara::JumpMotion(bool cflag)
{
	if (cflag)
	{
		// �v���C���[�̏���
		if ((Keyboard::GetKey(KEY_INPUT_SPACE) > 0
			|| Joypad::GetPad(XINPUT_BUTTON_A) > 0) 
			&& !jflag
			&& Map::GetMapData((int)y / 32 + 1,(int)(x + (Camera::c_moverX) / 2) / 32) == 0
			&& Map::GetMapData((int)y / 32 - 1, (int)((x + (Camera::c_moverX) / 2) - 15) / 32) == 1
			&& Map::GetMapData((int)y / 32 - 1, (int)((x + (Camera::c_moverX) / 2) + 15) / 32) == 1)
		{
			jy = -16.0;
			jflag = true;
		}
	}
	else
	{
		// �G�̏���
		timer++;
		if (timer == 180)
		{
			timer = 0;
			if (!jflag)
			{
				jy = -32.0;
				jflag = true;
			}
		}
	}

	// �W�����v�̈ړ�����
	if (jflag)
	{
		y = y + jy;
		jy = jy + 1.0;
		if (jy == 0
			|| Map::GetMapData((int)y / 32 - 1, (int)((x + (Camera::c_moverX) / 2) + 15) / 32) == 0
			|| Map::GetMapData((int)y / 32 - 1, (int)((x + (Camera::c_moverX) / 2) - 15) / 32) == 0)
		{
			jy = 0;
			jflag = false;
		}
	}
	else {}
}

// �U���q�b�g���̏���
void BaseChara::HitMotion()
{
	if (hitflag)
	{
		timer++;
		if (timer == 180)
		{
			hitflag = false;
			timer = 0;
		}
	}
	else {}
}

bool BaseChara::SideHitArea()
{
	if (muki == Muki::Right && Map::GetMapData((int)y / 32, (int)((x + (Camera::c_moverX) / 2)  + 18) / 32) == 0)
	{
		return false;
	}
	else if (muki == Muki::Left && Map::GetMapData((int)y / 32, (int)((x + (Camera::c_moverX) / 2) - 18) / 32) == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}