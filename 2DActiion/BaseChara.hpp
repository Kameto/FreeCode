#pragma once
#include "DxLib.h"
#include "Map.hpp"

enum Muki
{
	Right,
	Left,
	Num
};

class BaseChara
{
public:
	BaseChara();
	virtual ~BaseChara();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	bool HitChara();

	double x;
	double y;
	double bx;
	double by;
	double speed;
	double jumpspeed;
	int jumpcounter;
	bool jumpflag;
	Muki muki;
};