//
//	File	 : Player.h
//
//  Contents : CollisionSphereを継承したPlayerクラス
//
//	name	 : Hibiki Yoshiyasu
//
#pragma once
#include "../../Collision/CollisionSphere.h"
#include "../../Manager/Draw3DManager.h"

class Player : public CollisionSphere
{
public:
	// 行動パターン列挙体
	enum MOVE
	{
		STOP,			// 停止
		FORWARD,		// 前進
		BACK,			// 後退
		RIGHT_TURN,		// 右旋回
		LEFT_TURN,		// 左旋回
		RIGHT_FOR,	// 右斜め前
		RIGHT_BACK,	// 右斜め後ろ
		LEFT_FOR,	// 右斜め前
		LEFT_BACK,	// 右斜め後ろ
		DASH,		// 走る
	};
	const float MOVE_SPEED = 0.1f;	// 通常速度定数 
	const float DASH_SPEED = 0.2f;	// 走る速度定数

private:
	// 移動フラグ
	MOVE m_moveFlag;
	// 走るフラグ
	bool m_dashFlag;
	// 遅くなるフラグ
	bool m_srowFlag;

	// 鬼フラグ　true = 鬼
	bool m_oniFlag;

	// 発射フラグ
	bool m_shotFlag;

	// 停止フラグ
	bool m_stopFlag;
public:
	// コンストラクタ
	Player(DirectX::SimpleMath::Vector3 pos,float dir);

	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime);
	
	// 描画
	void Draw() override;

public:
	// ダッシュフラグを受け取る
	void SetDashFlag(bool on) {	m_dashFlag = on;}
	bool GetDashFlag() { return m_dashFlag; }
	
	// 遅くなるフラグを設定関数と取得関数
	void SetSrowFlag(bool on) { m_srowFlag = on; }
	bool GetSrowFlag() { return m_srowFlag; }

	// 発射設定関数と取得関数
	void SetShotFlag(bool on) { m_shotFlag = on; }
	bool GetShotFlag() { return m_shotFlag; }

	// 鬼フラグを受け取る
	void SetOniFlag(bool oniFlag) {	m_oniFlag = oniFlag; }

	// 移動フラグを取得
	MOVE GetMoFlag() { return m_moveFlag; }

	// 停止フラグを設定
	void SetStopFlag(bool stop) { m_stopFlag = stop; }
};