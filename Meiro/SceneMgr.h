#pragma once
#include "BaseScene.h"
#include "End.h"
#include "Game.h"
#include "Title.h"

class SceneMgr
{
public:
	SceneMgr();
	~SceneMgr();

	void Update();
	void Draw();

private:
	BaseScene* mpScene;
	DScene preScene;

	void ChangeScene();
};