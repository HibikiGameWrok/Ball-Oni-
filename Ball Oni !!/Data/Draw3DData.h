#pragma once
#include "../TaskSystem/TaskBase.h"

// モデルを描画する為に必要なデータ構造体
class Draw3DData : public Task::TaskBase
{
protected: // 変数
	// モデルファイル
	std::unique_ptr<DirectX::Model> m_modelFile;

	// 座標
	DirectX::SimpleMath::Vector3 m_pos;
	// 向き
	float m_dir;
	// 角度
	DirectX::SimpleMath::Quaternion m_rot;
	// サイズ
	DirectX::SimpleMath::Vector3 m_scale;
	// ワールド座標
	DirectX::SimpleMath::Matrix m_world;

	// 速度
	DirectX::SimpleMath::Vector3 m_vel;

public: // コンストラクタ&デストラクタ
	Draw3DData()
		: m_pos(DirectX::SimpleMath::Vector3::Zero)
		, m_dir(0.0f)
		, m_scale(1.0f, 1.0f, 1.0f)
		, m_world(DirectX::SimpleMath::Matrix::Identity)
		,m_vel(DirectX::SimpleMath::Vector3::Zero)
	{
	}
	~Draw3DData()
	{
	}

public: // 設定関数&取得関数
	// 座標の設定関数&取得関数
	void SetPos(const DirectX::SimpleMath::Vector3 position) { m_pos = position; }
	void SetPosX(float x) { m_pos.x = x; }
	void SetPosY(float y) { m_pos.y = y; }
	void SetPosZ(float z) { m_pos.z = z; }
	DirectX::SimpleMath::Vector3 GetPos() { return m_pos; }

	// 向きの設定関数&取得関数
	void SetDir(const float direction) { m_dir = direction; }
	float GetDir() { return m_dir; }

	// 角度
	void SetRot(const DirectX::SimpleMath::Quaternion rotation) { m_rot = rotation; }
	DirectX::SimpleMath::Quaternion GetRot() { return m_rot; }

	// サイズの設定関数&取得関数
	void SetScale(const DirectX::SimpleMath::Vector3 scale) { m_scale = scale; }
	DirectX::SimpleMath::Vector3 GetScale() { return m_scale; }

	// ワールド座標の設定関数&取得関数
	void SetWorld(const DirectX::SimpleMath::Matrix world) { m_world = world; }
	DirectX::SimpleMath::Matrix GetWorld() { return m_world; }

	// 速度変数の設定関数&取得関数
	void SetVel(const DirectX::SimpleMath::Vector3 vel) { m_vel = vel; }
	DirectX::SimpleMath::Vector3 GetVel() { return m_vel; }
};