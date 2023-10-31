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
	//ブロックのヒットポイント
	int m_hp;
	//当たり半径の矩形
	Rect m_colRect;
	//表示位置
	Vec2 m_pos;
	//存在しているかフラグ
	bool m_isExist;
};

