#include "Game.h"

Game::Game()
	: BaseScene()
{
	map = new Map();
	player = new Player(8 * 64, 8 * 64);
}

Game::~Game()
{
	delete player;
	player = nullptr;
	delete map;
	map = nullptr;
}

void Game::Update()
{
	player->Update();

	if (map->GetMapData(player->y / 64, player->x / 64) == 2)
	{
		nowScene = DScene::dEnd;
	}

//#ifdef _DEBUG
//	if (CheckHitKey(KEY_INPUT_2) == 1)
//	{
//		nowScene = DScene::dEnd;
//	}
//#endif
}

void Game::Draw()
{
	map->Draw();
	player->Draw();
}