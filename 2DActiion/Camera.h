#pragma once
#include "DxLib.h"

class Camera
{
public:
	Camera();
	~Camera();

	static void Update(int _y, int _x);
	static void Draw();
	static void SetCamera(int _y, int _x);
	static void SetCSpeed(int _speed);

	static int cameraX;
	static int cameraY;
	static int c_speed;
	static int c_moverX;
	static int c_moverY;
};