#include "BaseScene.h"

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