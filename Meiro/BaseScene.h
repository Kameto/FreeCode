#pragma once
#include "DxLib.h"
#include <string>
enum class DScene
{
	dTitle,
	dGame,
	dEnd
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();

	virtual void Update() = 0;
	virtual void Draw() = 0;
	DScene GetNowScene();
protected:
	static DScene nowScene;
};