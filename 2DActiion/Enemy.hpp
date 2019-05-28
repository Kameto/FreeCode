#pragma once
#include "BaseChara.hpp"

class Enemy :
	public BaseChara
{
public:
	Enemy();
	Enemy(int _y, int _x, int _mode, int _muki);
	~Enemy();
	void Update();
	void Draw();

private:
	int mode;
};