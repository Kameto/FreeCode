#pragma once
#include "Map.h"

enum Muki
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	NONE
};

class Player
{
public:
	Player();
	Player(int _y, int _x);
	~Player();
	void Update();
	void Draw();

	int x;
	int y;

private:
	int gr;
	bool moveFlag;
	Muki muki;

	bool HitArea();
};