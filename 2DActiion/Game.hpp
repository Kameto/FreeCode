#pragma once
#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Item.hpp"

class Game
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
	void GameTimer();

private:
	Player* player;
	Map* map;
	std::vector<Enemy*>enemy;
	std::vector<Item*>item;
	int min;
	int sec;
	bool timeflag;
};