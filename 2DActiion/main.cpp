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
	SetMainWindowText("2Dアクション");			// アプリケーション名
	ChangeWindowMode(false);					// スクリーン設定
	SetOutApplicationLogValidFlag(true);		// logファイルの生成
	SetGraphMode(1920, 1080, 32);				// 描画範囲
	
	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}

	SetFontSize(32);							// 文字サイズ設定

	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}

	Camera* camera = new Camera();
	Graph*		gra = new Graph();
	Map*		map = new Map();
	Joypad*		pad = new Joypad();
	Keyboard*	key = new Keyboard();
	SceneMgr*	smg = new SceneMgr();
	

	// メッセージループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		key->Update();
		pad->Update();
		smg->SceneUpdate();
		smg->SceneDraw();
		ScreenFlip();

		// アプリケーション終了用処理
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