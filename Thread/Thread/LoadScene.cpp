#include "LoadScene.h"

LoadScene::LoadScene()
{
	loadFlag = false;
	point = 0;
	timer = 0;
}

LoadScene::~LoadScene()
{
	loadFlag = false;
	point = 0;
	timer = 0;
}

void LoadScene::Update()
{
	if (Graphics::loadFlag)
	{
		point = x_point[3];
	}
	else
	{
		std::thread th1([] { Graphics::LoadGraphics(); });
		th1.join();
	}

	timer++;
	if (timer == 30)
	{
		timer = 0;
		loadFlag = true;
	}
}

void LoadScene::Draw()
{
	if (!loadFlag)
	{
		DrawGraph(0, 0, Graphics::GetGraph(GraphName::LoadPage), true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		DrawBox(point, 0, 1920, 1080, 0x00FFFF, true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}
	else
	{
		DrawGraph(0, 0, Graphics::GetGraph(GraphName::TitlePage), true);
		DrawGraph(0, 0, Graphics::GetGraph(GraphName::bom2), true);
	}

}