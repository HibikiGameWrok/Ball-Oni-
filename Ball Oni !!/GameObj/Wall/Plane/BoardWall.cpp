//
//	File	 : BoardWall.cpp
//
//  Contents : BoardWallクラス内の関数と変数の定義
//
//	name	 : Hibiki Yoshiyasu
//
#include "../../../pch.h"
#include "BoardWall.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


#pragma region Constructor
/// <summary>
/// コンストラクタ
/// </summary>
BoardWall::BoardWall()
{
}
BoardWall::BoardWall(DirectX::SimpleMath::Vector3 pos, float dir)
{
	m_pos = pos;
	m_dir = dir;
	// 大きさを10倍
	m_scale = Vector3(10.0f, 10.0f, 10.0f);

}
BoardWall::BoardWall(DirectX::SimpleMath::Vector3 pos, float dir, DirectX::SimpleMath::Vector3 boxRadius)
{
	m_pos = pos;
	m_dir = dir;

	// 大きさを10倍
	m_scale = Vector3(10.0f, 10.0f, 10.0f);

	// 当たり判定球型の設定
	Collision::Box box;
	box.c = Vector3(0.0f, 0.15f, 0.0f);
	box.r = Vector3(boxRadius);
	this->SetCollision(box);
}
#pragma endregion


#pragma region Destructor
/// <summary>
/// デストラクタ
/// </summary>
BoardWall::~BoardWall()
{
}
#pragma endregion


#pragma region Start
/// <summary>
/// 開始処理
/// </summary>
void BoardWall::Start()
{
	// ファイルパスを設定
	System::Draw3DManager::GetInstance().SetFilePath(m_modelFile,L"Resources\\Models\\Wall", L"Resources\\Models\\Wall\\Wall.cmo");

	// 向きを計算
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), XMConvertToRadians(m_dir));
	
	// ワールド座標を計算
	m_world = Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateScale(m_scale) * Matrix::CreateTranslation(m_pos);
}
#pragma endregion


#pragma region Update
/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">更新時間</param>
/// <returns>更新フラグ</returns>
bool BoardWall::Update(float elapsedTime)
{
	// 向きを計算
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), XMConvertToRadians(m_dir));

	// ワールド座標を計算
	m_world = Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateScale(m_scale) * Matrix::CreateTranslation(m_pos);
	return true;
}
#pragma endregion


#pragma region Draw
/// <summary>
/// 描画処理
/// </summary>
void BoardWall::Draw()
{
	// 描画
	System::Draw3DManager::GetInstance().Draw(m_modelFile,m_world);
}
#pragma endregion

/// <summary>
/// 当たり判定を設定
/// </summary>
void BoardWall::SetColWall(DirectX::SimpleMath::Vector3 boxCol)
{
	// 当たり判定球型の設定
	Collision::Box box;
	box.c = Vector3(0.0f, 0.15f, 0.0f);
	box.r = Vector3(boxCol);
	this->SetCollision(box);
}

