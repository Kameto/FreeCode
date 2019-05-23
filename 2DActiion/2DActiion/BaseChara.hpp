#pragma once
#include "DxLib.h"
#include "Map.hpp"

class BaseChara
{
public:
	BaseChara();
	virtual ~BaseChara();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	double x;
	double y;
	double bx;
	double by;
	double speed;
	bool jumpflag;
};