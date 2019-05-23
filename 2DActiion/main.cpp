#include "DxLib.h"
#include "Game.hpp"

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("Game_Name");				// アプリケーション名
	ChangeWindowMode(false);					// スクリーン設定
	SetOutApplicationLogValidFlag(true);		// logファイルの生成
	SetGraphMode(1920, 1080, 32);				// 描画範囲
	SetFontSize(32);							// 文字サイズ設定

	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}

	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}
	
	Game* game = new Game();
;
	// メッセージループ
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