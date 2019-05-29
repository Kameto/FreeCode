#pragma once
#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Item.hpp"
#include <random>

#define ENEMY_NUM	  7	// �G�̏��������� 
#define ITEM_NUM	  7	// �A�C�e���̏���������
#define START_TIME	 80	// �������Ԃ̏����ݒ�l
#define E_TO_B_RANGE 24	// �G�Ƌ��̏Փ˔͈�
#define P_TO_E_RANGE 32	// �v���C���[�ƓG�̏Փ˔͈�
#define P_TO_I_RANGE 40	// �v���C���[�ƃA�C�e���̏Փ˔͈�

class Game
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
	void GameTimer();

private:
	void GameDebugUpdate();
	void GameDebugDraw();

	Player* player;				// �v���C���[
	Map* map;					// �}�b�v
	std::vector<Enemy*>enemy;	// �G
	std::vector<Item*>item;		// �A�C�e��
	int min;					// �������ԗp�ϐ�
	int sec;					// �t���[���p�ϐ�
	bool timeflag;				// �������ԗp�t���O

	int itemcounter;
};