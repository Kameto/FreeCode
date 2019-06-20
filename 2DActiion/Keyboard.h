#pragma once
#include "DxLib.h"
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	static void Update();
	static int GetKey(int keycode);
	static void ReserKey(int keycode);

private:
	static int key[256];
	static char tmpkey[256];
};