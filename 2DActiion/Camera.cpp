#include "Camera.h"

int Camera::cameraX;
int Camera::cameraY;
int Camera::c_speed;
int Camera::c_moverX;
int Camera::c_moverY;

Camera::Camera()
{
	cameraX = 0;
	cameraY = 0;
	c_speed = 0;
	c_moverX = 0;
	c_moverY = 0;
}

Camera::~Camera()
{
	cameraX = 0;
	cameraY = 0;
	c_speed = 0;
	c_moverX = 0;
	c_moverY = 0;
}

void Camera::Update(int _y, int _x)
{
	if (_x <= 1824 && _x > cameraX + 384)
	{
		cameraX += c_speed;
		c_moverX += c_speed;
	}
	else if (_x >= 128 && _x < cameraX - 384)
	{
		cameraX -= c_speed;
		c_moverX -= c_speed;
	}

	if (_y > cameraY + 384)
	{
		cameraY += c_speed;
		c_moverY += c_speed;
	}
	else if (_y < cameraY - 384)
	{
		cameraY -= c_speed;
		c_moverY -= c_speed;
	}
}

void Camera::Draw()
{
	DrawBox(cameraX - 384, cameraY - 384, cameraX + 384, cameraY + 384, 0xFF0000, false);
}

void Camera::SetCamera(int _y, int _x)
{
	cameraX = _x;
	cameraY = _y;
}

void Camera::SetCSpeed(int _speed)
{
	c_speed = _speed;
}