//
//	File	 : Ball.h
//
//  Contents : CollisionSphereを継承したBallクラス
//
//	name	 : Hibiki Yoshiyasu
//
#pragma once
#include "../../Collision/CollisionSphere.h"
#include "../../Manager/Draw3DManager.h"
#include "../../StepTimer.h"

class Ball : public CollisionSphere
{
public:
	// ボールのスピード定数
	const float MOVE_SPEED = 0.3f;
public:
	// コンストラクタ
	Ball();

	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw() override;

	//----------Setter----------//
	// 発射フラグを受け取る
	void SetShotFlag(bool shotflag)
	{
		m_shotFlag = shotflag;
	}

	//----------Getter----------//
	// 発射フラグを返す
	bool GetShotFlag() {
		return m_shotFlag;
	}


private:
	// テストオブジェクト構造体
	//System::Draw3DData m_drawData;

	// 発射
	bool m_shotFlag;
};