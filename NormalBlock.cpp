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
	DrawGraph(0, 0, m_handle, true);
}
