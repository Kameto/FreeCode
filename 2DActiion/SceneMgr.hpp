#pragma once
#include "BaseScene.hpp"
#include "Game.hpp"
#include "Title.hpp"

class SceneMgr
{
public:
	SceneMgr();
	~SceneMgr();
	void SceneUpdate();	// 各シーンの処理
	void SceneDraw();	// 各シーンの描画

private:
	void ChangeScene();	// シーン切替

	BaseScene* mpScene;	// シーンデータ
	DScene preScene;	// 記録用シーンデータ
};