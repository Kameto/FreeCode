#include "DxLib.h"
#include "SceneMgr.h"

#define P_RELESE(x) delete (x); (x) = nullptr;

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("���H");				// �A�v���P�[�V������
	ChangeWindowMode(true);					// �X�N���[���ݒ�
	SetOutApplicationLogValidFlag(true);		// log�t�@�C���̐���
	SetGraphMode(1024, 768, 32);				// �`��͈�
	SetFontSize(16);							// �����T�C�Y�ݒ�

	if (DxLib_Init() == -1)						// Dx���C�u�����̏�����
	{
		return -1;
	}

	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// �w�i�`��ݒ�
	{
		return -1;
	}

	SceneMgr* mgr = new SceneMgr();

	// ���b�Z�[�W���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		mgr->Update();
		mgr->Draw();
		ScreenFlip();
	}

	InitSoundMem();
	InitGraph();
	P_RELESE(mgr);
	DxLib_End();
	return 0;
}