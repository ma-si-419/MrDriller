#pragma once
#include "Vec2.h"
#include "Rect.h"
class BlockBase
{
public:
	BlockBase();
	virtual ~BlockBase();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() const = 0;

	Rect GetColRect() const { return m_colRect; }

	void SetPos(Vec2 pos) { m_pos = pos; }

	//�V�[������v���C���[�ɃO���t�B�b�N��n��
	void SetHandle(int handle) { m_handle = handle; }

	bool IsExist() const { return m_isExist; }

protected:
	//�u���b�N�̃q�b�g�|�C���g
	int m_hp;
	//�����蔼�a�̋�`
	Rect m_colRect;
	//�\���ʒu
	Vec2 m_pos;
	//���݂��Ă��邩�t���O
	bool m_isExist;
	//�O���t�B�b�N
	int m_handle;
	//�u���b�N�̃J���[
	int m_color;
};

