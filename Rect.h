#pragma once
#include "Vec2.h"

/// <summary>
/// ��`���Ǘ����邽�߂̃N���X
/// </summary>
class Rect
{
public:
	Rect();
	virtual ~Rect();

	// �`��
	void Draw(unsigned int color, bool isFill) const;

	/// <summary>
	/// ������W�ƕ�, ������ۑ�
	/// </summary>
	/// <param name="left">���̍��W</param>
	/// <param name="top">��̍��W</param>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	void SetLT(float left, float top, float width, float height);

	/// <summary>
	/// ���S���W�ƕ�, ������ۑ�
	/// </summary>
	/// <param name="x">���S���W: x</param>
	/// <param name="y">���S���W: y</param>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	void SetCenter(float x, float y, float width, float height);

	// �K�v�ȏ����擾����
	float GetWidth() const;		// ��`�̕�
	float GetHeight() const;	// ��`�̍���
	Vec2 GetCenter() const;		// ��`�̒��S���W

	/// <summary>
	/// ��`���m�̓����蔻��
	/// </summary>
	/// <param name="target">���葤</param>
	/// <returns>true : ��������, false : �������ĂȂ�</returns>
	bool IsCollsion(const Rect& target);

	//�n�ʂɓ������Ă��邩�ǂ����𔻒肷��֐�
	bool IsGroundCollision(const Rect& target);
private:
	float m_left;	// ����X���W (����)
	float m_top;	// ���Y���W (����)
	float m_right;	// �E��Y���W (�E��)
	float m_bottom;	// ����Y���W (�E��)
};

