#pragma once
#include "Player.h"
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void Init();
	void Update();
	void Draw();

private:
	Player* m_pPlayer;
	// �O���t�B�b�N�̃n���h��
	int m_playerHandle;
};