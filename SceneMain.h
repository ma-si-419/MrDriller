#pragma once	
#include <vector>
using namespace std;

class Player;
class NormalBlock;
class Vec2;
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void Init();
	void Update();
	void Draw();
private:
	void CreateRedBlock();
	void CreateBlueBlock();
	void CreateYellowBlock();
private:
	//�v���C���[�̃|�C���^���i�[����ϐ�
	Player* m_pPlayer;
	//�u���b�N�̃|�C���^���i�[����ϐ�
	vector<NormalBlock*> m_pBlock;
	// �O���t�B�b�N�̃n���h��
	int m_playerHandle;
	int m_blockHandle;
};