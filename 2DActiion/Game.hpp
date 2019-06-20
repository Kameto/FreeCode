#pragma once
#include "BaseScene.hpp"
#include "Camera.h"
#include "Graph.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Item.hpp"

#define ENEMY_NUM	  7	// 敵の初期生成数 
#define ITEM_NUM	  7	// アイテムの初期生成数
#define START_TIME	 80	// 制限時間の初期設定値
#define E_TO_B_RANGE 24	// 敵と球の衝突範囲
#define P_TO_E_RANGE 32	// プレイヤーと敵の衝突範囲
#define P_TO_I_RANGE 40	// プレイヤーとアイテムの衝突範囲

#define BOX_EO( x, y, size, color) DrawBox( x*size, y*size, x*size+size, y*size+size, color, true);
#define BOX_EN( x, y, size, color) DrawBox( x*size, y*size, x*size+size, y*size+size, color, false);

class Game : 
	public BaseScene
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
	void MapDraw();
	void GameTimer();

private:
	Player* player;				// プレイヤー
	std::vector<Enemy*>enemy;	// 敵
	std::vector<Item*>item;		// アイテム
	int min;					// 制限時間用変数
	int sec;					// フレーム用変数
	bool timeflag;				// 制限時間用フラグ
	int itemcounter;
	int changetimer;
};