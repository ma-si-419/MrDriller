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
	//プレイヤーのポインタを格納する変数
	Player* m_pPlayer;
	//ブロックのポインタを格納する変数
	vector<NormalBlock*> m_pBlock;
	// グラフィックのハンドル
	int m_playerHandle;
	int m_blockHandle;
};