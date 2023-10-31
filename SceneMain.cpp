#include "SceneMain.h"
#include "Player.h"
#include "NormalBlock.h"
#include "DxLib.h"
#include<cassert>


SceneMain::SceneMain()
{
	// グラフィックのロード
	m_playerHandle = LoadGraph("data/image/player.png");
	assert(m_playerHandle != -1);
	m_blockHandle = LoadGraph("data/image/RedBlock.png");
	assert(m_blockHandle != -1);
	//プレイヤーのメモリ確保
	m_pPlayer = new Player;
	m_pPlayer->SetHandle(m_playerHandle);
	
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
}

void SceneMain::Update()
{
	m_pPlayer->Update();
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
}

void SceneMain::CreateRedBlock()
{
	for (int i = 0; i < m_pBlock.size(); i++)
	{
		if (!m_pBlock[i])	// nullptrであるチェック
		{
			m_pBlock[i] = new NormalBlock;
			m_pBlock[i]->Init();
			m_pBlock[i]->SetHandle(m_blockHandle);
			return;// 一体分確保できたら終了
		}
	}
}

void SceneMain::CreateBlueBlock()
{
	for (int i = 0; i < m_pBlock.size(); i++)
	{
		if (!m_pBlock[i])	// nullptrであるチェック
		{
			m_pBlock[i] = new NormalBlock;
			m_pBlock[i]->Init();
			m_pBlock[i]->SetHandle(m_blockHandle);
			return;// 一体分確保できたら終了
		}
	}
}

void SceneMain::CreateYellowBlock()
{
	for (int i = 0; i < m_pBlock.size(); i++)
	{
		if (!m_pBlock[i])	// nullptrであるチェック
		{
			m_pBlock[i] = new NormalBlock;
			m_pBlock[i]->Init();
			m_pBlock[i]->SetHandle(m_blockHandle);
			return;// 一体分確保できたら終了
		}
	}
}
