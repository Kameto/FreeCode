#pragma once
#include "BaseChara.hpp"

class Player :
	public BaseChara
{
public:
	Player();
	Player(double _x, double _y);
	~Player();

	void Update();
	void Draw();
	int GetX();
	int GetY();
};