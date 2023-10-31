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

private:
	//�u���b�N�̃q�b�g�|�C���g
	int m_hp;
	//�����蔼�a�̋�`
	Rect m_colRect;
	//�\���ʒu
	Vec2 m_pos;
	//���݂��Ă��邩�t���O
	bool m_isExist;
};

