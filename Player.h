#pragma once
#include"Vec2.h"
#include"Rect.h"
class Player
{
public:
	// �����Ă������
	enum Dir
	{
		kDirDown,	// ��
		kDirLeft,	// ��
		kDirRight,	// �E
		kDirUp		// ��
	};
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	virtual ~Player();

	//����������
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();

	//�V�[������v���C���[�ɃO���t�B�b�N��n��
	void SetHandle(int handle) { m_handle = handle; }

private:
	//�\���ʒu
	Vec2 m_pos;
	//�A�j���[�V�����̕\���ʒu
	Vec2 m_AnimPos;
	//�����蔻��p�̋�`
	Rect m_colRect;
	//�O���t�B�b�N
	int m_handle;
	// �����Ă������
	Dir m_dir;
	// �����A�j���[�V����
	int m_walkAnimFrame;
};

