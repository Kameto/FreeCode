#include "DxLib.h"
#include "SceneMgr.h"

#define P_RELESE(x) delete (x); (x) = nullptr;

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("迷路");				// アプリケーション名
	ChangeWindowMode(true);					// スクリーン設定
	SetOutApplicationLogValidFlag(true);		// logファイルの生成
	SetGraphMode(1024, 768, 32);				// 描画範囲
	SetFontSize(16);							// 文字サイズ設定

	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}

	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}

	SceneMgr* mgr = new SceneMgr();

	// メッセージループ
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