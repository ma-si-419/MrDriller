#include "DxLib.h"
#include "BlockBase.h"

namespace
{
	constexpr int kGraphWidth = 64;
	constexpr int kGraphHeight = 64;
}
BlockBase::BlockBase():
	m_hp(0),
	m_color(0),
	m_handle(-1)
{
}

BlockBase::~BlockBase()
{
}
void BlockBase::Update()
{
}
void BlockBase::Draw() const
{
	// ’†SˆÊ’u‚ğŠî€‚Æ‚µ‚Ä•`‰æ‚·‚é
	DrawRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		1.0, 0.0,
		m_handle, false, false);
}
void BlockBase::UpdateCollision()
{
	m_colRect.SetCenter(m_pos.x, m_pos.y, kGraphWidth, kGraphHeight);
}