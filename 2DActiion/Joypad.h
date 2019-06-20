#pragma once
#include "DxLib.h"
class Joypad
{
public:
	Joypad();
	~Joypad();
	static void Update();
	static int GetPad(int joycmd);
	static void ResetPad(int joycmd);

private:
	static XINPUT_STATE input;
	static int button[16];
};