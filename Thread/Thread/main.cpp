#include <DxLib.h>
#include "LoadScene.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("Game_Name");				// アプリケーション名

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(false);		// logファイルの生成
	ChangeWindowMode(true);						// スクリーン設定
#endif

#ifndef _DEBUG
	SetOutApplicationLogValidFlag(false);		// logファイルの生成
	ChangeWindowMode(false);					// スクリーン設定
#endif

	SetGraphMode(1920, 1080, 32);				// 描画範囲
	SetFontSize(16);							// 文字サイズ設定
	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}
	
	Graphics* grs = new Graphics("graph/0.png");
	LoadScene* ls = new LoadScene();


	// メッセージループ
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
//int sum = 0;// 足し算結果
//int xsum = 1;// 掛け算結果
//
//void FileLoad()
//{
//	string path, str, token;
//	ifstream ifs;
//	int x = 0, y = 0;
//
//	// pathに読み込みファイルの絶対・相対パスを代入する
//	path = "test.csv";
//
//	// 10x10の配列を生成
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
//	// .joinは実行完了まで他の処理は行わない
//	// .detachは処理を放棄する
//
//
//	thread t1(FileLoad);
//	t1.join();// joinを呼ぶことで関数内処理が終わるまで下の処理を行わないようにする。
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