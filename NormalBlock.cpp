#include "NormalBlock.h"
#include "DxLib.h"

NormalBlock::NormalBlock()
{
}

NormalBlock::~NormalBlock()
{
}

void NormalBlock::Init()
{
	m_isExist = true;
	m_color = GetRand(3);
}

void NormalBlock::Update()
{
	// 存在しないブロックの処理はしない
	if (!m_isExist) return;

	//当たり判定の更新 
	UpdateCollision();
}
