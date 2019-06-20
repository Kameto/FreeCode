#include "BaseScene.hpp"

DScene BaseScene::nowScene = DScene::dTitle;

BaseScene::BaseScene()
{
}

BaseScene::~BaseScene()
{
}

DScene BaseScene::GetNowScene()
{
	return nowScene;
}