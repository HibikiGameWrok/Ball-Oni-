//
//	File	 : Ball.cpp
//
//  Contents : Ballクラス内の関数と変数の定義
//
//	name	 : Hibiki Yoshiyasu
//
#include "../../pch.h"
#include "Ball.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

#pragma region Constructor
/// <summary>
/// コンストラクタ
/// </summary>
Ball::Ball()
	:m_shotFlag(false)
{

}
#pragma endregion

/// <summary>
/// 初期化処理
/// </summary>
void Ball::Start()
{
	System::Draw3DManager::GetInstance().SetFilePath(m_modelFile, L"Resources\\Models",L"Resources\\Models\\Ball.cmo");
	
	// 初期座標を設定
	m_pos = Vector3(0.0f, 0.0f, 0.0f);

	// 初期サイズを設定
	m_scale = Vector3(1.0f, 1.0f, 1.0f);

	// ワールド座標を更新
	m_world = Matrix::CreateScale(m_scale) * Matrix::CreateTranslation(m_pos);

	// 当たり判定球型の設定
	Collision::Sphere sphere;
	sphere.c = Vector3(0, 0, 0);
	sphere.r = 0.3f;
	this->SetCollision(sphere);
}

/// <summary>
/// 更新処理
/// </summary>
bool Ball::Update(float elapsedTime)
{
	// 発射フラグがtrueの時
	if (m_shotFlag == true)
	{
		m_vel.z = MOVE_SPEED;		// 速度ベクトルに速度定数を代入
		// m_vel : x,y軸は0、z軸に定数の値  m_rotation : プレイヤーの向きと同じ値
		Vector3 trans = Vector3::Transform(m_vel, m_rot);
		m_pos += trans;
	}


	// ワールド行列の作成
	// モデル自身を移動
	m_world = Matrix::CreateTranslation(m_pos);

	return true;
}


/// <summary>
/// 描画処理
/// </summary>
void Ball::Draw()
{
	// 描画
	System::Draw3DManager::GetInstance().Draw(m_modelFile, m_world);
}


