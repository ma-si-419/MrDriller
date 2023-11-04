#include "SceneMain.h"
#include "Player.h"
#include "NormalBlock.h"
#include "DxLib.h"
#include<cassert>

namespace
{
	constexpr int kBlockMax = 21;
}

SceneMain::SceneMain()
{
	// �O���t�B�b�N�̃��[�h
	m_playerHandle = LoadGraph("data/image/player.png");
	assert(m_playerHandle != -1);
	m_blockHandle = LoadGraph("data/image/GreenBlock.png");
	assert(m_blockHandle != -1);
	//�v���C���[�̃������m��
	m_pPlayer = new Player;
	m_pPlayer->SetHandle(m_playerHandle);
	//�u���b�N�̔z��̐ݒ�
	m_pBlock.resize(kBlockMax);
	for (int i = 0; i < m_pBlock.size(); i++)
	{
		m_pBlock[i] = nullptr;
	}
}

SceneMain::~SceneMain()
{
	// ����������O���t�B�b�N�̍폜
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_blockHandle);

	// �v���C���[�̃��������
	delete m_pPlayer;
	m_pPlayer = nullptr;

	// ���������m�ۂ���Ă���G��T���ĉ�����Ă���
	for (auto& block : m_pBlock)
	{
		if (block != nullptr)
		{
			delete block;
			block = nullptr;	// ���g�p��Ԃƕ�����悤�ɂ��Ă���
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
		if (block)	// nullptr�ł͂Ȃ��`�F�b�N : nullptr�łȂ�(�������������Ă���)�Ȃ瓮��
		{
			block->Update();

			// �g�p�ς݂̃u���b�N���폜����K�v������
			if (!block->IsExist())
			{
				// ���������������
				delete block;
				block = nullptr;	// �g���Ă��Ȃ��ƕ�����悤��
			}
			// �����ɂ���u���b�N�ƃv���C���[�Ɠ����蔻��
			else if (!playerRect.IsGroundCollision(block->GetColRect()))
			{
				//�v���C���[�̎��R�������~�߂�
				m_pPlayer->SetGroundFlag(false);
				// test
				//printfDx("�������Ă��Ȃ�\n");
			}
			else
			{
				m_pPlayer->SetGroundFlag(true);
				printfDx("�������Ă���\n");

			}
		}
	}
	Vec2 blockPos;
	blockPos.x += GetRand(60) + 320;
	blockPos.y = 440;

	//�o�Ă���u���b�N�A�C�e���Ɏ�ނ�����̂ŃX�C�b�`���ŕ�����
//	switch (GetRand(2))
//	{
//	case 0:	
		CreateBlock(blockPos);
//		break;
//	}
	
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
	for (const auto& block : m_pBlock)
	{
		if (block)	// nullptr�ł͂Ȃ��`�F�b�N
		{
			block->Draw();
		}
	}
}

void SceneMain::CreateBlock(Vec2 pos)
{
	for (int i = 0; i < m_pBlock.size(); i++)
	{
		if (!m_pBlock[i])	// nullptr�ł���`�F�b�N
		{
			m_pBlock[i] = new NormalBlock;
			m_pBlock[i]->Init();
			m_pBlock[i]->SetPos(pos);
			m_pBlock[i]->SetHandle(m_blockHandle);
			return;// ��̕��m�ۂł�����I��
		}
	}
}

