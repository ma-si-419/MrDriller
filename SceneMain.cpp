#include "SceneMain.h"
#include "Player.h"
#include "NormalBlock.h"
#include "DxLib.h"
#include<cassert>

namespace
{
	constexpr int kBlockMax = 1;
}

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
	//ブロックの配列の設定
	m_pBlock.resize(kBlockMax);
	for (int i = 0; i < m_pBlock.size(); i++)
	{
		m_pBlock[i] = nullptr;
	}
}

SceneMain::~SceneMain()
{
	// メモリからグラフィックの削除
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_blockHandle);

	// プレイヤーのメモリ解放
	delete m_pPlayer;
	m_pPlayer = nullptr;

	// メモリが確保されている敵を探して解放していく
	for (auto& block : m_pBlock)
	{
		if (block != nullptr)
		{
			delete block;
			block = nullptr;	// 未使用状態と分かるようにしておく
		}
	}
}

void SceneMain::Init()
{
}

void SceneMain::Update()
{
	m_pPlayer->Update();
	Rect playerRect = m_pPlayer->GetColRect();

	for (auto& block : m_pBlock)
	{
		if (block)	// nullptrではないチェック : nullptrでない(何かかが入っている)なら動作
		{
			block->Update();

			// 使用済みのブロックを削除する必要がある
			if (!block->IsExist())
			{
				// メモリを解放する
				delete block;
				block = nullptr;	// 使っていないと分かるように
			}
			// 存在しているブロックとプレイヤーと当たり判定
			else if (playerRect.IsCollsion(block->GetColRect()))
			{
				// test
				printfDx("当たっている\n");
			}
		}
	}
	switch (GetRand(2))
	{
	case 0:	// Letf
		CreateRedBlock();
		break;
	case 1:	// Right
		CreateBlueBlock();
		break;
	case 2:	// ToPlayer
		CreateYellowBlock();
		break;
	}
	
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
	for (const auto& block : m_pBlock)
	{
		if (block)	// nullptrではないチェック
		{
			block->Draw();
		}
	}
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
