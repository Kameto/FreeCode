#include "Graphics.h"

std::vector<int> Graphics::gr;
bool Graphics::loadFlag;

Graphics::Graphics()
{
	loadFlag = false;
}

Graphics::Graphics(std::string path)
{
	gr.resize(GraphName::all_num);
	int _gr = LoadGraph(path.c_str());
	if (_gr != -1)
	{
		gr[0] = _gr;
	}
	loadFlag = false;
}

Graphics::~Graphics()
{
	for (int i = 0, n = (unsigned)gr.size(); i < n; i++)
	{
		DeleteGraph(gr[i]);
		gr[i] = 0;
	}
	gr.erase(gr.begin(), gr.end());
	loadFlag = false;
}

void Graphics::LoadGraphics()
{
	std::string path;
	for (int i = 1, n = (unsigned)gr.size(), _gr = 0; i < n; i++)
	{
		path = "graph/" + std::to_string(i) + ".png";
		_gr = LoadGraph(path.c_str());
		if (_gr != -1)
		{
			gr[i] = _gr;
		}
		else
		{
			gr[i] = 0;
		}
	}
}

int Graphics::GetGraph(int _num)
{
	return gr[_num];
}