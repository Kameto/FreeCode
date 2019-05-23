#pragma once
#include "Map.hpp"
#include "Player.hpp"
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
	std::vector<Item*>item;

	int min;// •ª
	int sec;// •b
	bool timeflag;
};