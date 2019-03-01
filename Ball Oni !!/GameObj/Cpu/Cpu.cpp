//
//	File	 : Cpu.cpp
//
//  Contents : 宣言されたCpuクラスのメンバー関数とメンバー変数の定義
//
//	name	 : Hibiki Yoshiyasu
//
#include "../../pch.h"
#include "../../Control/Keyboard_Control.h"
#include "Cpu.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace System;

#pragma region Constructor
/// <summary>
/// コンストラクタ
/// </summary>
Cpu::Cpu(DirectX::SimpleMath::Vector3 pos, float dir)
	:m_moveFlag(STOP) // メンバー変数の初期化
	,m_frameTime_Ai(0)
	,m_secondsTime_Ai(0)
	,m_randAction(0)
	,m_stanTime(STAN_MAXTIME)
	,m_stanFlag(false)
	,m_shotFlag(false)
{
	m_pos = pos;
	m_dir = XMConvertToRadians(dir);
}
#pragma endregion 

#pragma region Start
/// <summary>
/// 初期化処理
/// </summary>
void Cpu::Start()
{
	// ファイルパス
	System::Draw3DManager::GetInstance().SetFilePath(m_modelFile, L"Resources\\Models", L"Resources\\Models\\CP.cmo");
	
	// 初期方向と角度を設定
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_dir);
	
	// 初期サイズを設定
	m_scale = Vector3(10.0f, 10.0f, 10.0f);
	
	// ワールド座標を更新
	m_world = Matrix::CreateScale(m_scale) *  Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);

	System::Draw3DManager::GetInstance().SetWorld(m_world);

	// 当たり判定カプセル型の設定
	Collision::Sphere sphere;
	sphere.c = Vector3(0, 0, 0);
	sphere.r = 0.3f;
	this->SetCollision(sphere);
}
#pragma endregion

#pragma region Update
/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">更新時間</param>
/// <returns>更新フラグ</returns>
bool Cpu::Update(float elapsedTime)
{
	m_vel = Vector3::Zero;
	static int timer = 0;
	if (m_stanFlag == false)
	{
		timer++;
		// 対象物へ角度を取得
		m_dir = TargetAngle(m_pos.x, m_pos.z, m_targetPos.x, m_targetPos.z);

		// 鬼の時は追いかける
		if (m_oniFlag == true)
		{
			m_vel.x = MOVE_SPEED / 2 * sin(m_dir);
			m_vel.z = MOVE_SPEED / 2 * cos(m_dir);

			// 玉を打つ確率を取得
			int shotRandom = 0;
			if (timer > 120)
			{
				shotRandom = rand() % 6 + 1;
				timer = 0;
			}
			if (m_shotFlag == false)
			{
				// shotRandomが1の時打つ
				m_shotFlag = shotRandom == 1 ? true : false;
			}
		}

		// 鬼じゃない時は逃げる
		if (m_oniFlag == false)
		{
			m_vel.x = MOVE_SPEED / 2 * sin(-m_dir);
			m_vel.z = MOVE_SPEED / 2 * cos(-m_dir);
		}


		/*Ai_Move();*/

		//switch (m_moveFlag)
		//{
		//case FORWARD:	// 前進
		//	m_vel.z = MOVE_SPEED;
		//	break;
		//case BACK:		// 後退
		//	m_vel.z = MOVE_SPEED * static_cast<float>(-0.5f);
		//	break;
		//case RIGHT_TURN:// 右旋回
		//	// プレイヤーの角度を見る
		//	m_dir -= XMConvertToRadians(45.0f);
		//	break;
		//case LEFT_TURN: // 左旋回
		//	m_dir += XMConvertToRadians(45.0f);
		//	break;
		//default:
		//	break;
		//}
	}
	
	Hit_DownMotion();
	
	// プレイヤーを移動させる
	// 指定した値を軸に回転
	Vector3 trans;
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f),m_dir + XMConvertToRadians(180));

	// 向きを変える
	//trans = Vector3::Transform(m_vel, m_rot);

	// 座標に向きと速度を与える
	m_pos -= m_vel;

	// 移動フラグをリセット
	/*m_moveFlag = STOP;*/

	// ワールド行列の作成
	// 回転してから移動
	m_world = Matrix::CreateScale(m_scale) * Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);
	//System::Draw3DManager::GetInstance().SetWorld(m_world);
	return true;
}
#pragma endregion 

#pragma region Draw
/// <summary>
/// 描画処理関数
/// </summary>
void Cpu::Draw()
{
	// 描画
	System::Draw3DManager::GetInstance().Draw(m_modelFile,m_world);
}
#pragma endregion 

#pragma region Ai_Move
/// <summary>
/// 簡易的タイマー式行動関数
/// </summary>
void Cpu::Ai_Move()
{
	// ニューラルネットワークオブジェクトを生成する
	m_pTheBrain = new NeuralNetwork();

	// ニューラルネットワークを初期化する
	m_pTheBrain->Initialize(2, 5, 3);

	// 学習率を設定する
	m_pTheBrain->SetLearningRate(0.3);

	// モメントを設定する
	m_pTheBrain->SetMomentum(true, 0.8);

	double	error = 1.0;
	int		count = 0;

	while (error > 0.01 && count < 10000) {
		error = 0.0;
		count++;
		for (int i = 0; i<MAX_NUM_DATA; i++) {
			m_pTheBrain->SetInput(0, TrainingSet[i][0]);			// 距離
			m_pTheBrain->SetInput(1, TrainingSet[i][1]);			// 鬼かどうか
			
			m_pTheBrain->SetDesiredOutput(0, TrainingSet[i][2]);	// 逃げる
			m_pTheBrain->SetDesiredOutput(1, TrainingSet[i][3]);	// 追いかける
			m_pTheBrain->SetDesiredOutput(2, TrainingSet[i][4]);	// 発射

			m_pTheBrain->FeedForward();								// 前方伝播する(Feed forward)
			error += m_pTheBrain->CalculateError();					// 誤差を計算する(Calculate error)
			m_pTheBrain->BackPropagate();							// 誤差逆伝播する(Back propagate)
		}
		error = error / MAX_NUM_DATA;
	}

	// 入力データをセットする
	m_pTheBrain->SetInput(0, 1.0); // 距離
	m_pTheBrain->SetInput(1, 0.7); // 鬼かどうか

	// ニューラルネットワークに出力データを問い合わせる
	m_pTheBrain->FeedForward();

	// 出力を取得
	m_pTheBrain->GetOutput(0);
	m_pTheBrain->GetOutput(1);
	m_pTheBrain->GetOutput(2);

	// 一番高い値の出力IDを取得
	int outputId = m_pTheBrain->GetMaxOutputID();

	// 値が高い出力によって行動をする
	switch (outputId)
	{
	case 0: // 逃げる
		
		break;
	case 1: // 追いかける
		
		break;
	case 2: // 発射

		break;
	
	default:
		break;
	}

}
#pragma endregion 

#pragma region Hit_DownMotion
/// <summary>
/// ダウンするモーション関数
/// </summary>
void Cpu::Hit_DownMotion()
{
	if (m_stanFlag == true)
	{
		m_stanTime -= 1;
		m_dir += XMConvertToRadians(10.0f);

		if (m_stanTime < 0)
		{
			m_stanFlag = false;
			m_stanTime = STAN_MAXTIME;
		}
	}
}
#pragma endregion 

#pragma region Move
/// <summary>
/// 移動処理
/// </summary>
/// <param name="move">MOVE列挙体</param>
void Cpu::Move(MOVE move)
{
	m_moveFlag = move;	// 指定された列挙体内の移動を呼ぶ
}
#pragma endregion 


/// <summary>
/// 対象物への角度を求める関数
/// </summary>
/// <returns>対象物へのY軸を基準とした角度</returns>
float Cpu::TargetAngle(float xMPos, float zMPos, float xTPos, float zTPos)
{
	// 対象物との差分を保管
	float dPosX;
	float dPosZ;
	// 求めた角度を保管
	float angle;

	// 対象物との差分を計算
	dPosX = xMPos - xTPos;
	dPosZ = zMPos - zTPos;

	// 差分によって角度を求める
	angle = atan2(dPosX, dPosZ);

	return angle;
}
