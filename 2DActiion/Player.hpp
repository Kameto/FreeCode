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
	
	int GetBX();
	int GetBY();

	bool atackflag;

private:
	double ballX;
	double ballY;
	
	Muki b_muki;
};