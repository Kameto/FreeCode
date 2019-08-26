#include <DxLib.h>
#include "LoadScene.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("Game_Name");				// �A�v���P�[�V������

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(false);		// log�t�@�C���̐���
	ChangeWindowMode(true);						// �X�N���[���ݒ�
#endif

#ifndef _DEBUG
	SetOutApplicationLogValidFlag(false);		// log�t�@�C���̐���
	ChangeWindowMode(false);					// �X�N���[���ݒ�
#endif

	SetGraphMode(1920, 1080, 32);				// �`��͈�
	SetFontSize(16);							// �����T�C�Y�ݒ�
	if (DxLib_Init() == -1)						// Dx���C�u�����̏�����
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// �w�i�`��ݒ�
	{
		return -1;
	}
	
	Graphics* grs = new Graphics("graph/0.png");
	LoadScene* ls = new LoadScene();


	// ���b�Z�[�W���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		ls->Update();
		ls->Draw();
		ScreenFlip();
	}
	
	delete ls;
	ls = nullptr;

	delete grs;
	grs = nullptr;

	DxLib_End();

	return 0;
}

//#include <thread>
//#include <string>
//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <vector>
//
//#include <DxLib.h>
//
//using namespace std;
//
//vector<vector<int>> map;
//int sum = 0;// �����Z����
//int xsum = 1;// �|���Z����
//
//void FileLoad()
//{
//	string path, str, token;
//	ifstream ifs;
//	int x = 0, y = 0;
//
//	// path�ɓǂݍ��݃t�@�C���̐�΁E���΃p�X��������
//	path = "test.csv";
//
//	// 10x10�̔z��𐶐�
//	map.resize(10);
//	for (int i = 0, n = (unsigned)map.size(); i < n; i++)
//	{
//		map[i].resize(10);
//	}
//
//	ifs.open(path.c_str());
//
//	if (!ifs.fail())
//	{
//		while (getline(ifs, str))
//		{
//			x = 0;
//			istringstream iss(str);
//			while (getline(iss, token, ','))
//			{
//				map[y][x] = stoi(token);
//				x++;
//			}
//			y++;
//		}
//	}
//
//	ifs.close();
//}
//
//void LoadSum()
//{
//	for (int i = 0, n = (unsigned)map.size(); i < n; i++)
//	{
//		for (int j = 0, m = (unsigned)map[i].size(); j < m; j++)
//		{
//			sum += map[i][j];
//		}
//	}
//}
//
//void LoadXSum()
//{
//	for (int i = 0, n = (unsigned)map.size(); i < n; i++)
//	{
//		for (int j = 0, m = (unsigned)map[i].size(); j < m; j++)
//		{
//			xsum *= map[i][j];
//		}
//	}
//}
//
//int main()
//{
//	// .join�͎��s�����܂ő��̏����͍s��Ȃ�
//	// .detach�͏������������
//
//
//	thread t1(FileLoad);
//	t1.join();// join���ĂԂ��ƂŊ֐����������I���܂ŉ��̏������s��Ȃ��悤�ɂ���B
//
//	for (int i = 0, n = (unsigned)map.size(); i < n; i++)
//	{
//		for (int j = 0, m = (unsigned)map[i].size(); j < m; j++)
//		{
//			if (j != m - 1)
//			{
//				cout << map[i][j] << ",";
//			}
//			else
//			{
//				cout << map[i][j] << endl;;
//			}
//		}
//	}
//	thread n1(LoadSum);
//	t1.swap(n1);
//	t1.join();
//	
//	cout << sum << endl;
//
//	thread n2(LoadSum);
//	t1.swap(n2);
//	t1.join();
//
//	cout << sum << endl;
//
//	for (int i = 0, n = (unsigned)map.size(); i < n; i++)
//	{
//		for (int j = 0, m = (unsigned)map[i].size(); j < m; j++)
//		{
//			map[i][j] = 0;
//		}
//	}
//	map.erase(map.begin(), map.end());
//
//	return 0;
//}