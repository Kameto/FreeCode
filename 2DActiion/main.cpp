// ここでは課題の試作を作っています
// 以下が条件です。〇は完成、△は途中、×は未完成です。
/*
・Xboxコントローラー対応						×
・ESCキーもしくはXboxコントローラーの
	StartボタンとBackボタン同時押しで終了する	△

・主人公が存在し、操作できる。
　-移動ができる									〇
　-ジャンプができる								△

 ・敵2種類以上
　敵はステータスのみの差ではなく、
	アルゴリズムの違いがあるものとする。		△

・画面が進行方向にスクロールする				×
・敵を倒すことができる							〇
・アイテム1種類以上								〇
・クリア条件がある								×
・画像表示を使っている							×
・音を出すことができる							×
*/

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