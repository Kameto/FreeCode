#include "SceneMgr.hpp"

SceneMgr::SceneMgr()
{
	mpScene = nullptr;
	mpScene = new Title();
}

SceneMgr::~SceneMgr()
{
	mpScene = nullptr;
	delete mpScene;
}

void SceneMgr::SceneUpdate()
{
	preScene = mpScene->GetNowScene();
	mpScene->Update();
	if (preScene != mpScene->GetNowScene())
	{
		ChangeScene();
	}
}

void SceneMgr::SceneDraw()
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
	default:
		break;
	}
}