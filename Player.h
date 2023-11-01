#pragma once
#include"Vec2.h"
#include"Rect.h"
class Player
{
public:
	// 向いている方向
	enum Dir
	{
		kDirDown,	// 下
		kDirLeft,	// 左
		kDirRight,	// 右
		kDirUp		// 上
	};
public:
	//コンストラクタ
	Player();
	//デストラクタ
	virtual ~Player();

	//初期化処理
	void Init();
	//更新処理
	void Update();
	//描画処理
	void Draw();

	//シーンからプレイヤーにグラフィックを渡す
	void SetHandle(int handle) { m_handle = handle; }

	//プレイヤーの当たり判定を取得する
	Rect GetColRect() { return m_colRect; }
private:
	//表示位置
	Vec2 m_pos;
	//アニメーションの表示位置
	Vec2 m_AnimPos;
	//当たり判定用の矩形
	Rect m_colRect;
	//グラフィック
	int m_handle;
	// 向いている方向
	Dir m_dir;
	// 歩きアニメーション
	int m_walkAnimFrame;
};

