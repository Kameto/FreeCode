#pragma once
#include "Camera.h"
#include "DxLib.h"
#include "Joypad.h"
#include "Keyboard.h"
#include "Map.hpp"
#include <random>

#define Gravty 4.0	// �d��
#define START_LIFE 5// �J�n���̗̑�

enum Muki
{
	Right,
	Left,
	None
};

class BaseChara
{
public:
	BaseChara();				// �R���X�g���N�^
	virtual ~BaseChara();		// �f�X�g���N�^
	virtual void Update() = 0;	// �s������
	virtual void Draw() = 0;	// �`��
	int GetX();					// X���W�擾
	int GetY();					// Y���W�擾
	int GetSpeed();

	int life;					// �̗�
	bool hitflag;				// �_���[�W����

protected:
	virtual void Atack() = 0;	// �U������
	void Move(bool cflag);		// �ړ�����
	void GravtyMotion();		// �d�͏���
	void JumpMotion(bool cflag);// �W�����v����
	void HitMotion();			// �U�����菈��
	bool SideHitArea();

	// ��{
	double x;
	double y;
	double bx;
	double by;
	double speed;

	// �W�����v
	double jcy;
	double jy;
	double jspeed;
	int jcounter;
	bool jflag;
	bool actflag;

	// ����
	Muki muki;
	Muki bc_muki;

	// ���̑�
	int timer;
};