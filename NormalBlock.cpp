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
}

void NormalBlock::Update()
{
	if (!m_isExist)
	{
		return;
	}
}

void NormalBlock::Draw() const
{
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}
