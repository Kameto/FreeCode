#pragma once
#include "DxLib.h"
#include "Map.hpp"

#define JumpSpeed 8.0
#define Gravty 4.0
#define START_LIFE 5

enum Muki
{
	Right,
	Left
};

class BaseChara
{
public:
	BaseChara();
	virtual ~BaseChara();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	int GetX();
	int GetY();

protected:
	virtual void Atack() = 0;	// 攻撃処理
	void GravtyMotion();		// 重力処理
	void JumpMotion();			// ジャンプ処理

	double x;
	double y;
	double bx;
	double by;
	double speed;
	int jumpcounter;
	int life;
	bool jumpflag;
	Muki muki;
};