#pragma once
#include <string>
#include <vector>
#include <DxLib.h>

enum GraphName
{
	LoadPage,
	TitlePage,
	bom1,
	bom2,
	bom3,
	nexus1,
	nexus2,
	nexus3,
	nexus4,
	player,
	all_num
};

class Graphics
{
public:
	Graphics();
	Graphics(std::string path);
	~Graphics();
	static void LoadGraphics();
	static int GetGraph(int _num);

	static bool loadFlag;

private:
	static std::vector<int>gr;
};