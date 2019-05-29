// �����ł͉ۑ�̎��������Ă��܂�
// �ȉ��������ł��B�Z�͊����A���͓r���A�~�͖������ł��B
/*
�EXbox�R���g���[���[�Ή�						�~
�EESC�L�[��������Xbox�R���g���[���[��
	Start�{�^����Back�{�^�����������ŏI������	��

�E��l�������݂��A����ł���B
�@-�ړ����ł���									�Z
�@-�W�����v���ł���								��

 �E�G2��ވȏ�
�@�G�̓X�e�[�^�X�݂̂̍��ł͂Ȃ��A
	�A���S���Y���̈Ⴂ��������̂Ƃ���B		��

�E��ʂ��i�s�����ɃX�N���[������				�~
�E�G��|�����Ƃ��ł���							�Z
�E�A�C�e��1��ވȏ�								�Z
�E�N���A����������								�~
�E�摜�\�����g���Ă���							�~
�E�����o�����Ƃ��ł���							�~
*/

#include "DxLib.h"
#include "Game.hpp"

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("Game_Name");				// �A�v���P�[�V������
	ChangeWindowMode(false);					// �X�N���[���ݒ�
	SetOutApplicationLogValidFlag(true);		// log�t�@�C���̐���
	SetGraphMode(1920, 1080, 32);				// �`��͈�
	SetFontSize(32);							// �����T�C�Y�ݒ�

	if (DxLib_Init() == -1)						// Dx���C�u�����̏�����
	{
		return -1;
	}

	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// �w�i�`��ݒ�
	{
		return -1;
	}
	
	Game* game = new Game();
;
	// ���b�Z�[�W���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		game->Update();
		game->Draw();
		ScreenFlip();
	}

	InitSoundMem();
	InitGraph();
	delete game;
	game = nullptr;
	DxLib_End();
	return 0;
}