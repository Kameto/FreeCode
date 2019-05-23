#include "DxLib.h"
#include "Map.hpp"
#include "Player.hpp"

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("Game_Name");				// アプリケーション名
	ChangeWindowMode(false);					// スクリーン設定
	SetOutApplicationLogValidFlag(true);		// logファイルの生成
	SetGraphMode(1920, 1080, 32);				// 描画範囲
	SetFontSize(16);							// 文字サイズ設定

	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}

	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}
	Player* player = new Player(512,96);
	Map* map = new Map();
	// メッセージループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		player->Update();
		player->Draw();
		map->Draw();
		ScreenFlip();
	}

	InitSoundMem();
	InitGraph();
	delete map;
	map = nullptr;
	delete player;
	player = nullptr;
	DxLib_End();
	return 0;
}