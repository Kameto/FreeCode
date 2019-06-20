#pragma once
#include "BaseScene.hpp"
#include "Camera.h"
#include "Graph.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Item.hpp"

#define ENEMY_NUM	  7	// �G�̏��������� 
#define ITEM_NUM	  7	// �A�C�e���̏���������
#define START_TIME	 80	// �������Ԃ̏����ݒ�l
#define E_TO_B_RANGE 24	// �G�Ƌ��̏Փ˔͈�
#define P_TO_E_RANGE 32	// �v���C���[�ƓG�̏Փ˔͈�
#define P_TO_I_RANGE 40	// �v���C���[�ƃA�C�e���̏Փ˔͈�

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
	Player* player;				// �v���C���[
	std::vector<Enemy*>enemy;	// �G
	std::vector<Item*>item;		// �A�C�e��
	int min;					// �������ԗp�ϐ�
	int sec;					// �t���[���p�ϐ�
	bool timeflag;				// �������ԗp�t���O
	int itemcounter;
	int changetimer;
};