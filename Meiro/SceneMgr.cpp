#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	mpScene = nullptr;
	preScene = DScene::dTitle;
	mpScene = new Title();
}

SceneMgr::~SceneMgr()
{
	delete mpScene;
	mpScene = nullptr;
}

void SceneMgr::Update()
{
	preScene = mpScene->GetNowScene();
	mpScene->Update();
	if (preScene != mpScene->GetNowScene())
	{
		ChangeScene();
	}
}

void SceneMgr::Draw()
{
	mpScene->Draw();
}

void SceneMgr::ChangeScene()
{
	if (mpScene != nullptr)
	{
		delete mpScene;
		mpScene = nullptr;
	}

	switch (mpScene->GetNowScene())
	{
	case DScene::dTitle:
		mpScene = new Title();
		break;
	case DScene::dGame:
		mpScene = new Game();
		break;
	case DScene::dEnd:
		mpScene = new End();
		break;
	default:
		break;
	}
}