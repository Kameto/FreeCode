#pragma once
#include "DxLib.h"
#include "Joypad.h"
#include "Keyboard.h"

enum class DScene
{
	dTitle,		// タイトル画面
	dGame,		// ゲーム画面
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual void Update() = 0;	// シーン処理
	virtual void Draw() = 0;	// シーン描画
	DScene GetNowScene();		// シーン情報

protected:
	static DScene nowScene;
};