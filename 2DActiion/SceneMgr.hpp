#pragma once
#include "BaseScene.hpp"
#include "Game.hpp"
#include "Title.hpp"

class SceneMgr
{
public:
	SceneMgr();
	~SceneMgr();
	void SceneUpdate();	// �e�V�[���̏���
	void SceneDraw();	// �e�V�[���̕`��

private:
	void ChangeScene();	// �V�[���ؑ�

	BaseScene* mpScene;	// �V�[���f�[�^
	DScene preScene;	// �L�^�p�V�[���f�[�^
};