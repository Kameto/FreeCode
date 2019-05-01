#include "End.h"

End::End()
	: BaseScene()
{
}

End::~End()
{
}

void End::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		nowScene = DScene::dTitle;
	}
//#ifdef _DEBUG
//	if (CheckHitKey(KEY_INPUT_3) == 1)
//	{
//		nowScene = DScene::dGame;
//	}
//#endif
}

void End::Draw()
{
	DrawBox(0, 0, 1024, 768, 0xFFFFFF, true);
	DrawFormatString(512, 320, 0x000000, "Now Scene : End");
	DrawFormatString(512, 384, 0x000000, "Push to Escape or Space");
}