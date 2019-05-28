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
	void Atack();
	void Jump();
	int GetX();
	int GetY();
	int GetBX();
	int GetBY();

private:
	int timer;
	double ballX;
	double ballY;
	bool atackflag;
	Muki muki;
	Muki b_muki;
};