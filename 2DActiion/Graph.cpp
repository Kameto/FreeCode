#include "Graph.hpp"

int Graph::back_gr = 0;
int Graph::tip_gr = 0;

Graph::Graph()
{
	back_gr = 0;
	tip_gr = 0;
	SetBackGraph();
	SetTipGraph();
}

Graph::~Graph()
{
	back_gr = 0;
	tip_gr = 0;
}

void Graph::SetBackGraph()
{
	int gr = LoadGraph("graph/back.png");
	if (gr != (-1 || 0))
	{
		back_gr = gr;
	}
	else
	{
		back_gr = 0;
	}
}

void Graph::SetTipGraph()
{
	int gr = LoadGraph("graph/wall2.png");
	if (gr != (-1 || 0))
	{
		tip_gr = gr;
	}
	else
	{
		tip_gr = 0;
	}
}

int Graph::GetBackGraph()
{
	return back_gr;
}

int Graph::GetTipGraph()
{
	return tip_gr;
}