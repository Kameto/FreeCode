#include "Title.hpp"

Title::Title()
{
}

Title::~Title()
{
}

void Title::Update()
{
	if (Keyboard::GetKey(KEY_INPUT_RETURN) > 10
	 || Joypad::GetPad(XINPUT_BUTTON_START) > 10)
	{
		BaseScene::nowScene = DScene::dGame;
	}
}

void Title::Draw()
{
	DrawBox(0, 0, 1920, 1080, 0xFFFFFF, true);
	DrawBox(10, 10, 1910, 1070, 0x0f0f0f, true);
	DrawString(1920 / 4, (1080 / 2) - 128, "2D_Action Game", 0xFFFF00, true);
	DrawString(1920 / 4, 1080 / 2, "pless Enter or Xbox start button", 0xFF00FF, true);

	DrawFormatString(20,20,0xFFFFFF,"%d",Keyboard::GetKey(KEY_INPUT_RETURN));
}