#include "Game.hpp"

Game::Game()
{
	map = new Map();
	player = new Player(512, 96);
	enemy.resize(0);
	enemy.push_back(new Enemy(840, 128, 0, 0));
	enemy.push_back(new Enemy(840, 256, 0, 1));
	item.resize(0);
	for (int i = 0; i < 7; i++)
	{
		item.push_back(new Item(128, i * 32));
	}
	min = 60;
	sec = 0;
	timeflag = false;
}

Game::~Game()
{
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
	player->Update();

	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		if (abs(player->GetX() - item[i]->x) < 24 &&
			abs(player->GetY() - item[i]->y) < 24)
		{
			min += 5;
			item.erase(item.begin() + i);
			break;
		}
	}

	for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
	{
		enemy[i]->Update();
	}
	GameTimer();

#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			item.push_back(new Item(128, i * 32));
		}
	}
#endif
}

void Game::Draw()
{
	DrawBox(0, 0, 1920, 1080, 0xFFFF00, true);
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		item[i]->Draw();
	}
	map->Draw();
	player->Draw();
	for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
	{
		enemy[i]->Draw();
	}
#ifdef _DEBUG
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		if (abs(player->GetX() - item[i]->x) < 24 &&
			abs(player->GetY() - item[i]->y) < 24)
		{
			DrawFormatString(0, 32, 0xFF0000, "Hit_Now!!!");
		}
	}
#endif

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