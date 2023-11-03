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
	if (!m_isExist)
	{
		return;
	}
}
