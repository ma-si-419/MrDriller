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

	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() { return m_colRect; }

	//�n�ʂɓ������Ă��邩�ǂ����ݒ肷��
	void SetGroundFlag(bool _isFlag) { m_isGroundFlag = _isFlag; }
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
	//�n�ʂɂ��Ă邩�ǂ���
	bool m_isGroundFlag;
};

