#pragma once
#include "Camera.h"
#include "DxLib.h"
#include "Joypad.h"
#include "Keyboard.h"
#include "Map.hpp"
#include <random>

#define Gravty 4.0	// 重力
#define START_LIFE 5// 開始時の体力

enum Muki
{
	Right,
	Left,
	None
};

class BaseChara
{
public:
	BaseChara();				// コンストラクタ
	virtual ~BaseChara();		// デストラクタ
	virtual void Update() = 0;	// 行動処理
	virtual void Draw() = 0;	// 描画
	int GetX();					// X座標取得
	int GetY();					// Y座標取得
	int GetSpeed();

	int life;					// 体力
	bool hitflag;				// ダメージ判定

protected:
	virtual void Atack() = 0;	// 攻撃処理
	void Move(bool cflag);		// 移動処理
	void GravtyMotion();		// 重力処理
	void JumpMotion(bool cflag);// ジャンプ処理
	void HitMotion();			// 攻撃判定処理
	bool SideHitArea();

	// 基本
	double x;
	double y;
	double bx;
	double by;
	double speed;

	// ジャンプ
	double jcy;
	double jy;
	double jspeed;
	int jcounter;
	bool jflag;
	bool actflag;

	// 向き
	Muki muki;
	Muki bc_muki;

	// その他
	int timer;
};