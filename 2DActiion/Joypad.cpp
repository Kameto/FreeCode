#include "Joypad.h"

XINPUT_STATE Joypad::input;
int Joypad::button[16];

Joypad::Joypad()
{
	for (int i = 0; i < 16; i++)
	{
		button[i] = 0;
	}
}

Joypad::~Joypad()
{
	for (int i = 0; i < 16; i++)
	{
		button[i] = 0;
	}
}

void Joypad::Update()
{
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	for (int i = 0; i < 16; i++)
	{
		if (input.Buttons[i] > 0)
		{
			button[i]++;
		}
		else
		{
			button[i] = 0;
		}
	}
}

int Joypad::GetPad(int joycmd)
{
	return button[joycmd];
}

void Joypad::ResetPad(int joycmd)
{
	button[joycmd] = 0;
}