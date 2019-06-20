#include "Camera.h"
#include "DxLib.h"
#include "Graph.hpp"
#include "Joypad.h"
#include "Keyboard.h"
#include "Map.hpp"
#include "SceneMgr.hpp"

#define RELESE(x) delete (x); if((x) != nullptr){(x) = nullptr;}

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("2D�A�N�V����");			// �A�v���P�[�V������
	ChangeWindowMode(false);					// �X�N���[���ݒ�
	SetOutApplicationLogValidFlag(true);		// log�t�@�C���̐���
	SetGraphMode(1920, 1080, 32);				// �`��͈�
	
	if (DxLib_Init() == -1)						// Dx���C�u�����̏�����
	{
		return -1;
	}

	SetFontSize(32);							// �����T�C�Y�ݒ�

	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// �w�i�`��ݒ�
	{
		return -1;
	}

	Camera* camera = new Camera();
	Graph*		gra = new Graph();
	Map*		map = new Map();
	Joypad*		pad = new Joypad();
	Keyboard*	key = new Keyboard();
	SceneMgr*	smg = new SceneMgr();
	

	// ���b�Z�[�W���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		key->Update();
		pad->Update();
		smg->SceneUpdate();
		smg->SceneDraw();
		ScreenFlip();

		// �A�v���P�[�V�����I���p����
		if (key->GetKey(KEY_INPUT_ESCAPE) == 1
			|| (pad->GetPad(XINPUT_BUTTON_START) == 1 && pad->GetPad(XINPUT_BUTTON_BACK) == 1))
		{
			break;
		}
	}

	RELESE(gra);
	RELESE(map);
	RELESE(pad);
	RELESE(key);
	RELESE(smg);
	RELESE(camera);

	InitSoundMem();
	InitGraph();
	DxLib_End();
	return 0;
}