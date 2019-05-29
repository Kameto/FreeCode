#include "Game.hpp"

Game::Game()
{
	// ランダム用変数設定
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> e_rnd(0, 50);

	// 初期化・生成
	map = new Map();
	player = new Player(512, 96);	

	enemy.resize(0);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy.push_back(new Enemy(512, i * 64, e_rnd(mt) % 2, e_rnd(mt) % 2));
	}
	item.resize(0);

	std::uniform_int_distribution<> h_rnd(2, Map::GetmapSizeY() - 2);	// マップ縦範囲
	std::uniform_int_distribution<> w_rnd(2, Map::GetMapSizeX() - 60);	// マップ横範囲
	itemcounter = 0;
	for (int i = 0, px = 0, py = 0; i < ITEM_NUM; i++)
	{
		while (true)
		{
			px = h_rnd(mt);
			py = w_rnd(mt);
			if (Map::GetMapData(px, py) == 0)
			{
				itemcounter++;
				continue;
			}
			else
			{
				item.push_back(new Item(py * TIP_SIZE, px * TIP_SIZE));
				break;
			}
		}
	}
	min = START_TIME;
	sec = 0;
	timeflag = false;
}

Game::~Game()
{
	// 再初期化・解放
	if (!item.empty())
	{
		for (int i = 0, n = (unsigned)item.size(); i < n; i++)
		{
			delete item[i];
			item[i] = nullptr;
		}
	}
	item.erase(item.begin(), item.end());
	if (!enemy.empty())
	{
		for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
		{
			delete enemy[i];
			enemy[i] = nullptr;
		}
	}
	enemy.erase(enemy.begin(), enemy.end());
	delete player;
	player = nullptr;
	delete map;
	map = nullptr;
	min = 0;
	sec = 0;
	timeflag = false;
}

void Game::Update()
{
	// プレイヤーの処理
	player->Update();

	// アイテムの判定処理
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		if (abs(player->GetX() - item[i]->x) < P_TO_I_RANGE &&
			abs(player->GetY() - item[i]->y) < P_TO_I_RANGE)
		{
			min += 5;
			item.erase(item.begin() + i);
			break;
		}
	}

	// 敵の処理
	if (!enemy.empty())
	{
		for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
		{
			enemy[i]->Update();

			// プレイヤーとの判定処理
			if (abs(player->GetX() - enemy[i]->GetX()) < P_TO_E_RANGE &&
				abs(player->GetY() - enemy[i]->GetY()) < P_TO_E_RANGE)
			{
				// ライフの減少処理
			}

			// 球との判定処理
			if (abs(player->GetBX() - enemy[i]->GetX()) < E_TO_B_RANGE &&
				abs(player->GetBY() - enemy[i]->GetY()) < E_TO_B_RANGE)
			{
				player->atackflag = false;
				enemy.erase(enemy.begin() + i);
				break;
			}
		}
	}

	// 制限時間タイマー
	GameTimer();

#ifdef _DEBUG
	GameDebugUpdate();
#endif
}

void Game::Draw()
{
	// 背景
	DrawBox(0, 0, 1920, 1080, 0xFFFF00, true);
	
	// アイテムの描画
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		item[i]->Draw();
	}

	// マップの描画
	map->Draw();
	
	// プレイヤーの描画
	player->Draw();
	
	// 敵の描画
	for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
	{
		enemy[i]->Draw();
	}

	// 制限時間タイマーの描画
	DrawCircle(0, 0, 50, 0xFFFFFF, true);
	DrawCircle(0, 0, 50, 0xFF0000, false);
	if (min > 10)
	{
		if (min >= 99)
		{
			DrawFormatString(0, 0, 0xFF0000, "99+");
		}
		else
		{
			DrawFormatString(0, 0, 0xFF0000, "%d", min);
		}
	}
	else
	{
		DrawFormatString(0, 0, 0xFF0000, "0%d", min);
	}

#ifdef _DEBUG
	GameDebugDraw();
#endif

}

void Game::GameDebugUpdate()
{
	// アイテム生成
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			item.push_back(new Item(192, i * 32));
		}
	}
}

void Game::GameDebugDraw()
{
	// 敵との判定debugコメント表示
	DrawFormatString(640, 0, 0xFF0000, "Enemy");
	for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
	{
		if (abs(player->GetX() - enemy[i]->GetX()) < P_TO_E_RANGE &&
			abs(player->GetY() - enemy[i]->GetY()) < P_TO_E_RANGE)
		{
			DrawFormatString(640, 32, 0xFF0000, "Hit_Now!!!");
		}
	}

	// アイテムの判定debugコメント表示
	DrawFormatString(768, 0, 0xFF0000, "Item");
	DrawFormatString(768, 32, 0xFF0000, "reset: %d", itemcounter);
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		if (abs(player->GetX() - item[i]->x) < 24 &&
			abs(player->GetY() - item[i]->y) < 24)
		{
			DrawFormatString(768, 64, 0xFF0000, "Hit_Now!!!");
		}
		DrawFormatString(960, (i * 32), 0xFF0000, "Y: %d .X: %d", (item[i]->y / 32), (item[i]->x / 32));
	}
}

void Game::GameTimer()
{
	if (!timeflag)
	{
		if (sec == 0)
		{
			sec = 179;
			min--;
		}
		else
		{
			sec--;
		}
	}

	if (min == 0)
	{
		timeflag = true;
	}
}