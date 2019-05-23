#include "Game.hpp"

Game::Game()
{
	map = new Map();
	player = new Player(512, 96);
	item.resize(0);
	for (int i = 0; i < 7; i++)
	{
		item.push_back(new Item(128, i * 32));
	}
	min = 5;
	sec = 0;
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
	delete player;
	player = nullptr;
	delete map;
	map = nullptr;
}

void Game::Update()
{
	player->Update();
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		if (abs(player->GetX() - item[i]->x) < 24 &&
			abs(player->GetY() - item[i]->y) < 24)
		{
			item.erase(item.begin() + i);
			break;
		}
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
	player->Draw();
	map->Draw();
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
	if (sec > 10)
	{
		DrawFormatString(960, 0, 0xFF000000, "%d : %d", min, sec);
	}
	else 
	{
		DrawFormatString(960, 0, 0xFF000000, "%d : 0%d", min, sec);
	}

}

void Game::GameTimer()
{
	if (timeflag)
	{
		min--;
		if (min == 0)
		{
			min = 59;
			sec--;
		}
	}

	if (sec == 0 && min == 0)
	{
		timeflag = false;
	}
}