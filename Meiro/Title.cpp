#include "Title.h"

Title::Title()
	: BaseScene()
{
}

Title::~Title()
{
}

void Title::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		nowScene = DScene::dGame;
	}
//#ifdef _DEBUG
//	if (CheckHitKey(KEY_INPUT_1) == 1)
//	{
//		nowScene = DScene::dGame;
//	}
//#endif
}

void Title::Draw()
{
	DrawBox(0, 0, 1024, 768, 0xFFFFFF, true);
	DrawFormatString(512, 320, 0x000000, "Now Scene : Title");
	DrawFormatString(512, 384, 0x000000, "Push to Escape or Enter");
}