#include "Keyboard.h"

int Keyboard::key[256];
char Keyboard::tmpkey[256];

Keyboard::Keyboard()
{
	for (int i = 0; i < 256; i++)
	{
		key[i] = 0;
		tmpkey[i] = 0;
	}
}

Keyboard::~Keyboard()
{
	for (int i = 0; i < 256; i++)
	{
		key[i] = 0;
		tmpkey[i] = 0;
	}
}

void Keyboard::Update()
{
	GetHitKeyStateAll(tmpkey);
	for (int i = 0; i < 256; i++)
	{
		if (tmpkey[i] > 0)
		{
			key[i]++;
		}
		else
		{
			key[i] = 0;
		}
	}
}

int Keyboard::GetKey(int keycode)
{
	return key[keycode];
}

void Keyboard::ReserKey(int keycode)
{
	key[keycode] = 0;
}