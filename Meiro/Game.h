#pragma once
#include "BaseScene.h"
#include "Map.h"
#include "Player.h"

class Game :
	public BaseScene
{
public:
	Game();
	~Game();

	void Update();
	void Draw();

private:
	Map* map;
	Player* player;
};