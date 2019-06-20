#pragma once
#include "DxLib.h"
#include "Joypad.h"
#include "Keyboard.h"

enum class DScene
{
	dTitle,		// �^�C�g�����
	dGame,		// �Q�[�����
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual void Update() = 0;	// �V�[������
	virtual void Draw() = 0;	// �V�[���`��
	DScene GetNowScene();		// �V�[�����

protected:
	static DScene nowScene;
};