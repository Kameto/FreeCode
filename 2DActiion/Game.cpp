#include "Game.hpp"

Game::Game()
{
	// �����_���p�ϐ��ݒ�
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> e_rnd(0, 10);

	// �������E����
	player = new Player(512, 512);
	Camera::SetCamera(player->GetY(), player->GetX());
	Camera::SetCSpeed(player->GetSpeed());

	enemy.resize(0);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy.push_back(new Enemy(512, (i * 64) + 64 , e_rnd(mt) % 2, e_rnd(mt) % 2));
	}
	item.resize(0);

	std::uniform_int_distribution<> h_rnd(2, Map::GetmapSizeY() - 2);	// �}�b�v�c�͈�
	std::uniform_int_distribution<> w_rnd(2, Map::GetMapSizeX() - 55);	// �}�b�v���͈�
	itemcounter = 0;
	for (int i = 0, px = 0, py = 0; i < ITEM_NUM; i++)
	{
		while (true)
		{
			py = h_rnd(mt);
			px = w_rnd(mt);
			if (Map::GetMapData(py, px) == 0)
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
	changetimer = 0;
}

Game::~Game()
{
	// �ď������E���
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
	min = 0;
	sec = 0;
	timeflag = false;
	changetimer = 0;
}

void Game::Update()
{
	// �v���C���[�̏���
	player->Update();
	Camera::Update(player->GetY(), player->GetX());

	// �S�[���ɂ�����
	if (Map::GetMapData(player->GetY() / 32, player->GetX() / 32) == 2)
	{
		timeflag = true;
	}

	// �A�C�e���̔��菈��
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

	// �G�̏���
	if (!enemy.empty())
	{
		for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
		{
			enemy[i]->Update();

			// �v���C���[�Ƃ̔��菈��
			if (abs(player->GetX() - enemy[i]->GetX()) < P_TO_E_RANGE &&
				abs(player->GetY() - enemy[i]->GetY()) < P_TO_E_RANGE)
			{
				if (!player->hitflag && player->life > 0)
				{
					player->life--;
					player->hitflag = true;
					if (player->life == 0)
					{
						timeflag = true;
						break;
					}
				}
				else {}
			}

			// ���Ƃ̔��菈��
			if (abs(player->GetBX() - enemy[i]->GetX()) < E_TO_B_RANGE &&
				abs(player->GetBY() - enemy[i]->GetY()) < E_TO_B_RANGE)
			{
				player->atackflag = false;
				if (!enemy[i]->hitflag && enemy[i]->life > 0)
				{
					enemy[i]->life--;
					enemy[i]->hitflag = true;
					if (enemy[i]->life == 0)
					{
						enemy.erase(enemy.begin() + i);
						break;
					}
				}
				else {}
			}
		}
	}
	else
	{
		timeflag = true;
	}

	// �������ԃ^�C�}�[
	GameTimer();

	if (timeflag)
	{
		changetimer++;
		if (changetimer == 5)
		{
			BaseScene::nowScene = DScene::dTitle;
		}
	}
	else{}
}

void Game::Draw()
{
	// �w�i
	DrawBox(0, 0, 1920, 1080, 0xFFFF00, true);
	
	// �A�C�e���̕`��
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		item[i]->Draw();
	}

	MapDraw();
	
	// �v���C���[�̕`��
	player->Draw();
	
	// �G�̕`��
	for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
	{
		enemy[i]->Draw();
	}

	Camera::Draw();

	// �������ԃ^�C�}�[�̕`��
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

void Game::MapDraw()
{
	for (int i = 0, n = Map::GetmapSizeY(); i < n; i++)
	{
		for (int j = 0 , m = Map::GetMapSizeX() ; j < m; j++)
		{
			BOX_EN(j, i, TIP_SIZE, 0x000000);
			if (Map::GetMapData(i, j) == 0)
			{
				if (Graph::GetTipGraph() != (-1 || 0))
				{
					DrawGraph((j * TIP_SIZE) - (Camera::c_moverX / 2), i * TIP_SIZE, Graph::GetTipGraph(), true);
				}
				else
				{
					BOX_EO(j, i, TIP_SIZE, 0xFFFF00);
				}
			}
			else if (Map::GetMapData(i, j) == 2)
			{
				BOX_EO(j, i, TIP_SIZE, 0xFF0000);
			}
		}
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