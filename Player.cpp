#include "Player.h"
#include "Game.h"
#include <DxLib.h>
namespace
{
	// �ړ����x
	constexpr float kSpeed = 3.0f;
	// �L�����N�^�[�̃T�C�Y
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;
	// �����̃T�C�Y
	constexpr float kGraphHalfWidth = kGraphWidth / 2.0f;
	constexpr float kGraphHalfHeight = kGraphHeight / 2.0f;
	// �L�����N�^�[�̃A�j���[�V����
	constexpr int kUseFrame[] = { 0, 1, 2, 1 };
	// �A�j���[�V����1�R�}�̃t���[����
	constexpr int kAnimFrameNum = 6;
	// �A�j���[�V�����̂P�T�C�N���̃t���[����
	constexpr int kAnimFrameCycle = _countof(kUseFrame) * kAnimFrameNum;
}
Player::Player():
	m_walkAnimFrame(kAnimFrameNum),
	m_handle(-1),
	m_dir(kDirDown),
	m_pos(Game::kScreenWidth / 2, Game::kScreenHeight / 2)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	// �p�b�h�̏\���L�[���g�p���ăv���C���[���ړ�������
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//�ړ��ʂ����悤�ɂ���
	Vec2 move{ 0.0f,0.0f };

	bool isMove = false;

	if (pad & PAD_INPUT_UP)
	{
		m_dir = kDirUp;

		if (m_pos.y < 0)	m_pos.y = 0;
	}
	if (pad & PAD_INPUT_DOWN)
	{
		m_dir = kDirDown;

		if (Game::kScreenHeight - kGraphHeight < m_pos.y)	m_pos.y = Game::kScreenHeight - kGraphHeight;
	}
	if (pad & PAD_INPUT_LEFT)
	{
		move.x--;
		m_dir = kDirLeft;
		isMove = true;

		if (m_pos.x < 0)	m_pos.x = 0;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		move.x++;
		m_dir = kDirRight;
		isMove = true;

		if (Game::kScreenWidth - kGraphWidth < m_pos.x)	m_pos.x = Game::kScreenWidth - kGraphWidth;
	}
	// ���K��
	move.Normalize();
	// �����̕ύX
	move *= kSpeed;
	// ���W�Ƀx�N�g���𑫂�
	m_pos += move;
	// �c���̈ړ�����
	if (m_pos.y < kGraphHalfHeight)
		m_pos.y = kGraphHalfHeight;
	else if (Game::kScreenHeight - kGraphHalfHeight < m_pos.y)
		m_pos.y = Game::kScreenHeight - kGraphHalfHeight;
	// �����̈ړ�����
	if (m_pos.x < kGraphHalfWidth)
		m_pos.x = kGraphHalfWidth;
	else if (Game::kScreenWidth - kGraphHalfWidth < m_pos.x)
		m_pos.x = Game::kScreenWidth - kGraphHalfWidth;

	// �����蔻��̍X�V
	m_colRect.SetCenter(m_pos.x, m_pos.y, kGraphWidth, kGraphHeight);
	// �΂߈ړ��̏ꍇ�����������ňړ�����悤�ɂ���
	if (isMove)
	{
		// �����A�j���[�V����
		m_walkAnimFrame++;
		if (kAnimFrameCycle <= m_walkAnimFrame)	m_walkAnimFrame = 0;
	}
	else
	{
		if (kUseFrame[m_walkAnimFrame / kAnimFrameNum] != 1)
		{
			m_walkAnimFrame++;
		}
		else
		{
			m_walkAnimFrame = kAnimFrameNum;
		}
	}
}

void Player::Draw()
{
//	if (m_damageFrame % 4 >= 2) return;

	//�A�j���[�V����
	m_AnimPos.x = kGraphWidth * kUseFrame[m_walkAnimFrame / kAnimFrameNum];
	m_AnimPos.y = kGraphHeight * m_dir;

	DrawRectRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		static_cast<int>(m_AnimPos.x), static_cast<int>(m_AnimPos.y),
		kGraphWidth, kGraphHeight,
		1.0, 0.0,
		m_handle, true, false);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", static_cast<int>(m_AnimPos.x));
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", static_cast<int>(m_pos.x));
}
