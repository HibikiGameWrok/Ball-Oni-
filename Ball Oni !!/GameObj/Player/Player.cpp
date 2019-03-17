//
//	File	 : Player.cpp
//
//  Contents : Playerクラスの関数と変数の定義
//
//	name	 : Hibiki Yoshiyasu
//
#include "../../pch.h"
#include "../../Control/keyboard_control.h"
#include "Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace System;

#pragma region Constructor
/// <summary>
/// コンストラクタ
/// </summary>
Player::Player(DirectX::SimpleMath::Vector3 pos,float dir)
	: m_moveFlag(STOP),m_dashFlag(false), m_oniFlag(false), m_stopFlag(true) // メンバー変数の初期化
{
	m_pos = pos;
	m_dir = XMConvertToRadians(dir);
}
#pragma endregion

#pragma region Update
/// <summary>
/// 初期化処理
/// </summary>
void Player::Start()
{
	Draw3DManager::GetInstance().SetFilePath(m_modelFile, L"Resources\\Models", L"Resources\\Models\\PL.cmo");

	// 初期方向と角度を設定
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_dir);

	// 初期サイズを設定
	m_scale = Vector3(10.0f, 10.0f, 10.0f);

	// ワールド座標を計算
	m_world = Matrix::CreateScale(m_scale) * Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);
	Draw3DManager::GetInstance().SetWorld(m_world);

	// 当たり判定球型の設定
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
bool Player::Update(float elapsedTime)
{ 
	if (m_stopFlag == false)
	{
		// コントロール更新
		Key_Control::GetInstance().Update();
		__int8 action = Key_Control::GetInstance().GetActionVal();
		// 遅くなるフラグに取得
		m_srowFlag = Key_Control::GetInstance().GetDashFlag();
		// 発射フラグを取得
		m_shotFlag = Key_Control::GetInstance().GetShotFlag();

		// 速度をリセットする
		m_vel = Vector3::Zero;

		// 列挙体のパターン
		switch (action)
		{
		case FORWARD:	    // 前進
			if (m_dashFlag) {
				m_vel.z = DASH_SPEED;
			}
			else {
				m_vel.z = MOVE_SPEED;
			}
			break;
		case BACK:		    // 後退
			if (m_dashFlag) {
				m_vel.z = DASH_SPEED * static_cast<float>(-0.5f);
			}
			else {
				m_vel.z = MOVE_SPEED * static_cast<float>(-0.5f);
			}
			break;
		case LEFT_TURN:    // 右移動
			m_dir += XMConvertToRadians(2.0f);
			break;
		case RIGHT_TURN:     // 左移動
			m_dir -= XMConvertToRadians(2.0f);
			break;
		case RIGHT_FOR:	// 右旋回
			if (m_dashFlag)
			{
				m_dir -= XMConvertToRadians(2.0f);
				m_vel.x = DASH_SPEED * static_cast<float>(-0.3f);
				m_vel.z = DASH_SPEED;
			}
			else
			{
				m_dir -= XMConvertToRadians(2.0f);
				m_vel.x = MOVE_SPEED * static_cast<float>(-0.5f);
				m_vel.z = MOVE_SPEED;
			}
			break;
		case RIGHT_BACK:  // 右斜め後ろ
			if (m_dashFlag)
			{
				m_vel.x = DASH_SPEED * static_cast<float>(-0.5f);
				m_vel.z = DASH_SPEED * static_cast<float>(-0.5f);
			}
			else
			{
				m_vel.x = MOVE_SPEED * static_cast<float>(-0.5f);
				m_vel.z = MOVE_SPEED * static_cast<float>(-0.5f);
			}
			break;
		case LEFT_FOR:	// 左旋回
			if (m_dashFlag)
			{
				m_dir += XMConvertToRadians(2.0f);
				m_vel.x = DASH_SPEED * static_cast<float>(0.3f);
				m_vel.z = DASH_SPEED;
			}
			else
			{
				m_dir += XMConvertToRadians(2.0f);
				m_vel.x = MOVE_SPEED * static_cast<float>(0.5f);
				m_vel.z = MOVE_SPEED;
			}
			break;
		case LEFT_BACK:	// 左斜め後ろ移動
			if (m_dashFlag)
			{
				m_vel.x = DASH_SPEED * static_cast<float>(0.5f);
				m_vel.z = DASH_SPEED * static_cast<float>(-0.5f);
			}
			else
			{
				m_vel.x = MOVE_SPEED * static_cast<float>(0.5f);
				m_vel.z = MOVE_SPEED * static_cast<float>(-0.5f);
			}
			break;
		default:
			break;
		}
		Key_Control::GetInstance().SetAction(Key_Control::NONE);

		// プレイヤーを移動させる
		// 指定した値を軸に回転
		Vector3 trans;
		m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_dir);

		// 座標へ速度と向きを代入
		trans = Vector3::Transform(m_vel, m_rot);
		m_pos += trans;

		// ワールド行列の作成
		// 回転してから移動
		m_world = Matrix::CreateScale(m_scale) * Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);

		System::Draw3DManager::GetInstance().SetWorld(m_world);
	}
	return true; 
}

#pragma endregion

#pragma region Draw
/// <summary>
/// 描画処理
/// </summary>
void Player::Draw()
{
	// 描画
	System::Draw3DManager::GetInstance().Draw(m_modelFile, m_world);
}
#pragma endregion

