#pragma once
#include "../../DeviceResources.h"

#include "../Player/Player.h"
#include "../Ball/Ball.h"

//#include "../../../mycamera.h"


class ModelManager
{
public:
	// コンストラクタ
	ModelManager();
	// デストラクタ
	~ModelManager();

	// 初期化関数
	void Initialize();

	// 作成関数
	void Create(DX::DeviceResources* deviceResources);

	// 更新処理
	bool Update(float elapsedTime);

	// 描画情報をもらう関数
	void Render(DirectX::SimpleMath::Matrix view,
		DirectX::SimpleMath::Matrix projection);

	// 解放関数
	void Finalize();
private:
	// キャラクター
	//void CreatePlayer(Collision::Sphere sphere, DX::DeviceResources * deviceResources);
	//void CreateBall(Collision::Sphere sphere, DX::DeviceResources * deviceResources);
	// 壁
	void CreatePlaneWall(Collision::Box box, DX::DeviceResources * deviceResources);
	void SetPramePlaneWall(int i, DirectX::SimpleMath::Vector3 pos,float dir);
	// T壁
	void CreateTWall(Collision::Box box, DX::DeviceResources * deviceResources);
	void SetPrameTWall(int i, DirectX::SimpleMath::Vector3 pos, float dir);
private:
	// 当たり判定の管理
	void HitManagement();
public: 
	// プレイヤーの移動を指示する関数
	void PlayerControl();	
public:
	// カメラ
	//DirectX::SimpleMath::Vector3 GetEye()
	//{
	//	return m_camera.GetEyePosition();
	//}
	//DirectX::SimpleMath::Vector3 GetTarget()
	//{
	//	return m_camera.GetTargetPosition();
	//}
private:
	static const int NUM_BOARDW_WALL = 32;
	//-----ここから描画するモデルのクラス変数を宣言-----------------------------//
	Player*			m_player;		// プレイヤー
	Ball*			m_ball;		    // ボール
	//--------------------------------------------------//
private:
	// キーボード
	std::unique_ptr<DirectX::Keyboard> m_keyboard;
	// キーボードトラッカー
	DirectX::Keyboard::KeyboardStateTracker m_tracker;

	// コモンステート
	DirectX::CommonStates* m_states;
	// ビュー行列
	//DirectX::SimpleMath::Matrix m_view;
	// 射影行列
	//DirectX::SimpleMath::Matrix m_projection;

	// カメラオブジェクト
	//GameCamera m_camera;
private:
	int m_oniNum;								// 鬼かどうか
	int m_stamina;								// スタミナの値
};