//
//	File	 : Cpu.h
//
//  Contents : CollisionSphereクラスを継承したCpuクラス
//
//	name	 : Hibiki Yoshiyasu
//
#pragma once
#include "../../Collision/CollisionSphere.h"
#include "../../Manager/Draw3DManager.h"
#include "../../MyNeuralNetwork/MyNeuralNetwork.h"

class Cpu : public CollisionSphere
{
public:
	static const int MAX_NUM_DATA = 5;			 // ニューラルネットワーク
	const float MOVE_SPEED = 0.1f;		 // 速度定数
	const float STAN_MAXTIME = 180.0f;   // スタン時間定数
public:
	float TrainingSet[MAX_NUM_DATA][5] = {
		//input[距離,鬼かどうか],output[逃げる,追いかける,発射]
		0.9,1.0, 0.9,0.4,0.2,
		0.8,1.0, 0.8,0.6,0.3,
		0.6,1.0, 0.6,0.5,0.3,
		0.3,0.0, 0.2,0.4,0.7,
		0.1,0.0, 0.1,0.3,0.9
	};

	// 行動パターン
	enum MOVE
	{
		STOP,		// 停止
		FORWARD,	// 前進
		BACK,		// 後退
		RIGHT_TURN,	// 右旋回
		LEFT_TURN,  // 左旋回
	};
private:
	NeuralNetwork* m_pTheBrain;

	// 移動フラグ
	MOVE m_moveFlag;

	// AI 時間管理変数
	int m_frameTime_Ai;
	int m_secondsTime_Ai;
	// 行動を判断する為の乱数変数
	int m_randAction;

	// 鬼かどうか知るフラグ true == 鬼
	bool m_oniFlag;
	// 発射フラグ
	bool m_shotFlag;

	// スタンタイム
	float m_stanTime;
	// スタン状態か見るフラグ
	bool m_stanFlag;

	// 相手の座標を保管する変数
	DirectX::SimpleMath::Vector3 m_targetPos;

public:
	// コンストラクタ
	Cpu(DirectX::SimpleMath::Vector3 pos,float dir);

	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime);
	
	// 描画
	void Draw() override;

private:
	// 移動する関数
	void Move(MOVE move);

	// 簡易AI
	void Ai_Move();

	// ダウンモーション
	void Hit_DownMotion();

public:
	// 距離
	void SetTargetPos(DirectX::SimpleMath::Vector3 tpos) { m_targetPos = tpos; };

	float TargetAngle(float xMPos, float zMPos, float xTPos, float zTPos);

	// 移動フラグ取得関数
	MOVE GetMoFlag() { return m_moveFlag; }

	// 鬼フラグを設定関数と取得関数
	void SetOniFlag(bool oniFlag) { m_oniFlag = oniFlag; }
	bool GetOniFlag() { return m_oniFlag; }

	// スタンフラグを設定関数と取得関数
	void SetStanFlag(bool stan) { m_stanFlag = stan; }
	bool GetStanFlag() { return m_stanFlag; }

	// 発射設定関数と取得関数
	void SetShotFlag(bool on) { m_shotFlag = on; }
	bool GetShotFlag() { return m_shotFlag; }
};
