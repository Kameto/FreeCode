#pragma once
#include "DxLib.h"

class Graph
{
public:
	Graph();
	~Graph();

	static void SetBackGraph();
	static void SetTipGraph();
	static int GetBackGraph();
	static int GetTipGraph();

private:
	static int back_gr;
	static int tip_gr;
};