#pragma once
#include "../../DeviceResources.h"

// インクルードは噛み合わせ注意

class ModelObject 
{
public:
	ModelObject();
	~ModelObject();

	// 初期化関数
	virtual void Initialize() = 0;

	// 作成関数
	void Create(DX::DeviceResources* deviceResources,  const wchar_t* effectFile, const wchar_t* cmoFile);
	
	// 更新処理
	virtual bool Update(float elapsedTime) = 0;
	
	// 描画情報をもらう関数
	virtual void Render(DirectX::CommonStates* states,DirectX::SimpleMath::Matrix view,
		DirectX::SimpleMath::Matrix projection) = 0;
	
	// 解放関数
	virtual void Finalize() = 0;

public:
	/*-----Setter-----*/
	// モデルハンドルを設定する関数
	void SetModel(DirectX::Model* model) {
		m_model = model;
	}

	// 位置を設定する関数
	void SetPosition(DirectX::SimpleMath::Vector3 position) {
		m_pos = position;
	}
	void SetPosition(float xPos, float yPos, float zPos)
	{
		m_pos = DirectX::SimpleMath::Vector3(xPos, yPos, zPos);
	}

	// 回転を設定する関数
	void SetRotation(DirectX::SimpleMath::Quaternion rotation) {
		m_rotation = rotation;
	}

	//向きを受け取る
	void SetDir(float dir) {
		m_direction = dir;
	}

	// 大きさを設定する関数
	void SetScale(DirectX::SimpleMath::Vector3 scale) {
		m_scale = scale;
	}
	void SetScale(float scale) {
		m_scale.x = scale;
		m_scale.y = scale;
		m_scale.z = scale;
	}

	// 速度を受け取る
	void SetVel(DirectX::SimpleMath::Vector3 vel) {
		m_vel = vel;
	}
	void SetVel(float xVel, float yVel, float zVel) {
		m_vel = DirectX::SimpleMath::Vector3(xVel, yVel, zVel);
	}
	// 速度をゼロにする
	void ResetVel(DirectX::SimpleMath::Vector3 velZero)
	{
		m_vel = velZero;
	}

	/*-----Getter-----*/
	// 座標を取得する関数
	virtual DirectX::SimpleMath::Vector3 GetPosition() {
		return m_pos;
	}
	// X座標を取得する
	float GetXPos()
	{
		return m_pos.x;
	}
	// Y座標を取得する
	float GetYPos()
	{
		return m_pos.y;
	}
	// Z座標を取得する
	float GetZPos()
	{
		return m_pos.z;
	}

	// 向きを取得
	float GetDir() {
		return m_direction;
	}

	// 回転を取得
	DirectX::SimpleMath::Quaternion GetRotation() {
		return m_rotation;
	}

	// 速度を取得
	DirectX::SimpleMath::Vector3 GetVel() {
		return m_vel;
	}

protected:
	// コンテキスト
	ID3D11DeviceContext* m_context;

	// モデル
	std::unique_ptr<DirectX::Model> m_modelFile;
	
	// モデルハンドル
	DirectX::Model* m_model;
	
	// 向き (float型)
	float m_direction;

	// 大きさ (Vector3型)
	DirectX::SimpleMath::Vector3 m_scale;

	// 速度	(Vector3型)
	DirectX::SimpleMath::Vector3 m_vel;

	// グローバル座標
	DirectX::SimpleMath::Vector3 m_pos;

	// 回転 (Quaternion型)
	DirectX::SimpleMath::Quaternion m_rotation;

	// ワールド行列
	DirectX::SimpleMath::Matrix m_world;
};