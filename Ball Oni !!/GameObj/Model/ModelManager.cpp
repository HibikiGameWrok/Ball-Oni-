#include "../../pch.h"
#include "ModelManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
ModelManager::ModelManager()
	:m_oniNum(1)
	,m_stamina(100)
{
}

/// <summary>
/// デストラクタ
/// </summary>
ModelManager::~ModelManager()
{
}


/// <summary>
/// 初期化処理
/// </summary>
void ModelManager::Initialize()
{
}


/// <summary>
/// 作成関数
/// </summary>
/// <param name="deviceResources">デバイスリソース</param>
/// <param name="game">ゲームオブジェクト</param>
void ModelManager::Create(DX::DeviceResources * deviceResources)
{
	//// 引数から受け取ったデバイスとコンテキストをメンバー変数に保管
	//ID3D11Device*  device = deviceResources->GetD3DDevice();
	//// コモンステートの作成
	//m_states = new CommonStates(device);

	//// 当たり判定の範囲
	//Collision::Box box;
	//Collision::Sphere sphere;

#pragma region "ここに作成したいモデルの作成関数を呼ぶ"
	//CreateSkyBox(deviceResources);
	//CreateFloor(box, deviceResources);
    //CreatePlayer(sphere, deviceResources);
	//CreateCpu(sphere, deviceResources);
	//CreateBall(sphere, deviceResources);
	//CreatePlaneWall(box, deviceResources);
	//CreateTWall(box, deviceResources);
#pragma endregion
}
#pragma region CreateCharactera
	/*プレイヤーの作成*/
	//void ModelManager::CreatePlayer(Collision::Sphere sphere, DX::DeviceResources * deviceResources)
	//{
	//	m_player = new Player();
	//	m_player->Create(deviceResources, L"Resources\\Models", L"Resources\\Models\\PL.cmo");
	//	m_player->SetScale(1);
	//	m_player->SetPosition(Vector3(0, 0.3f, 5));
	//	m_player->SetDir(90.0f);
	//	sphere.c = Vector3(0, 0, 0);			// 芯線の開始点
	//	sphere.r = 0.3f;						// 半径
	//	m_player->SetCollision(deviceResources,sphere);
	//}
	/*ボールの作成*/
	//void ModelManager::CreateBall(Collision::Sphere sphere, DX::DeviceResources * deviceResources)
	//{
	//	m_ball = new Ball();
	//	m_ball->Create(deviceResources, L"Resources\\Models", L"Resources\\Models\\Ball.cmo");
	//	m_ball->SetScale(1);
	//	if (m_oniNum == 1)
	//	{
	//		m_ball->SetPosition(m_player->GetPosition().x, m_player->GetPosition().y + 0.5f, m_player->GetPosition().z);
	//	}
	//	//if (m_oniNum == 2)
	//	//{
	//	//	m_ball->SetPosition(m_cpu->GetPosition().x, m_cpu->GetPosition().y + 0.5f, m_cpu->GetPosition().z);
	//	//}
	//	sphere.c = Vector3(0, 0, 0);
	//	sphere.r = 0.1f;
	//	m_ball->SetCollision(deviceResources,sphere);
	//}
#pragma endregion
	/*板状の壁の作成*/
#pragma region CreateWAll
//	void ModelManager::CreatePlaneWall(Collision::Box box, DX::DeviceResources * deviceResources)
//	{
//		for (int i = 0; i < NUM_BOARDW_WALL; i++)
//		{
//			m_boardWall[i] = new BoardWall();
//			m_boardWall[i]->Create(deviceResources, L"Resources\\Models\\Wall", L"Resources\\Models\\Wall\\Wall.cmo");
//			m_boardWall[i]->SetScale(10);
//		}
//		// 壁の番号に座標と角度の設定
//#pragma region 前
//		SetPramePlaneWall(0, Vector3(0, 0, 19), 0);
//		SetPramePlaneWall(1, Vector3(3, 0, 19), 0);
//		SetPramePlaneWall(2, Vector3(-3, 0, 19), 0);
//		SetPramePlaneWall(3, Vector3(6, 0, 19), 0);
//		SetPramePlaneWall(4, Vector3(-6, 0, 19), 0);
//		SetPramePlaneWall(5, Vector3(9, 0, 19), 0);
//		SetPramePlaneWall(6, Vector3(-9, 0, 19), 0);
//		SetPramePlaneWall(7, Vector3(12, 0, 19), 0);
//#pragma endregion
//#pragma region 後ろ
//		SetPramePlaneWall(8, Vector3(0, 0, -5), 0);
//		SetPramePlaneWall(9, Vector3(3, 0, -5), 0);
//		SetPramePlaneWall(10, Vector3(-3, 0, -5), 0);
//		SetPramePlaneWall(11, Vector3(6, 0, -5), 0);
//		SetPramePlaneWall(12, Vector3(-6, 0, -5), 0);
//		SetPramePlaneWall(13, Vector3(9, 0, -5), 0);
//		SetPramePlaneWall(14, Vector3(-9, 0, -5), 0);
//		SetPramePlaneWall(15, Vector3(12, 0, -5), 0);
//#pragma endregion 
//#pragma region 右
//		SetPramePlaneWall(16, Vector3(13, 0, -3), 90);
//		SetPramePlaneWall(17, Vector3(13, 0, 0), 90);
//		SetPramePlaneWall(18, Vector3(13, 0, 3), 90);
//		SetPramePlaneWall(19, Vector3(13, 0, 6), 90);
//		SetPramePlaneWall(20, Vector3(13, 0, 9), 90);
//		SetPramePlaneWall(21, Vector3(13, 0, 12), 90);
//		SetPramePlaneWall(22, Vector3(13, 0, 15), 90);
//		SetPramePlaneWall(23, Vector3(13, 0, 18), 90);
//#pragma endregion
//#pragma region 左
//		SetPramePlaneWall(24, Vector3(-10, 0, -3), 90);
//		SetPramePlaneWall(25, Vector3(-10, 0, 0), 90);
//		SetPramePlaneWall(26, Vector3(-10, 0, 3), 90);
//		SetPramePlaneWall(27, Vector3(-10, 0, 6), 90);
//		SetPramePlaneWall(28, Vector3(-10, 0, 9), 90);
//		SetPramePlaneWall(29, Vector3(-10, 0, 12), 90);
//		SetPramePlaneWall(30, Vector3(-10, 0, 15), 90);
//		SetPramePlaneWall(31, Vector3(-10, 0, 18), 90);

		// コリジョンデータの設定
		// 横向き
		//Collision::Box box_front;
		//box_front.c = Vector3(0.0f, 0.15f, 0.0f);
		//box_front.r = Vector3(0.15f, 0.15f, 0.05f);
		//// 縦向き
		//Collision::Box box_back;
		//box_back.c = Vector3(0.0f, 0.15f, 0.0f);
		//box_back.r = Vector3(0.05f, 0.15f, 0.15f);

		// コリジョンデータをセット
		//for (int i = 0; i < NUM_BOARDW_WALL; i++)
		//{
		//	if (i < 16)	{
		//		m_boardWall[i]->SetCollision(deviceResources, box_front);
		//	}
		//	else if (i >= 16) {
		//		m_boardWall[i]->SetCollision(deviceResources, box_back);
		//	}
		//}
	//}
	//板状の壁のパラメータ設定(番号、座標、角度)//
	//void ModelManager::SetPramePlaneWall(int i, DirectX::SimpleMath::Vector3 pos, float dir)
	//{
	//	// i番目の座標を設定
	//	m_boardWall[i]->SetPosition(pos);
	//	// i番目の角度を設定
	//	m_boardWall[i]->SetDir(dir);
	//}
	/*T字の壁の作成*/
	//void ModelManager::CreateTWall(Collision::Box box, DX::DeviceResources * deviceResources)
	//{
	//	m_tWall = new TShapedWall();
	//	m_tWall->Create(deviceResources, L"Resources\\Models\\Wall", L"Resources\\Models\\Wall\\T_Wall.cmo");
	//	m_tWall->SetScale(10);
	//	SetPrameTWall(0, Vector3(5, 0, 0), 0);
	//	Collision::Box twoBox[2];
	//	// コリジョンデータの設定
	//	twoBox[0].c = Vector3(0.0f, 0.15f, 0.0f);
	//	twoBox[0].r = Vector3(0.2f, 0.15f, 0.05f);
	//	twoBox[1].c = Vector3(0.0f, 0.15f, 0.1f);
	//	twoBox[1].r = Vector3(0.05f, 0.15f, 0.15f);
	//	// コリジョンデータをセット
	//	for (int i = 0; i < 2; i++)
	//	{
	//		m_tWall->Set2Collision(deviceResources,i, twoBox[i]);
	//	}
	//}
	//T字の壁のパラメータ設定(番号、座標、角度)//
	//void ModelManager::SetPrameTWall(int i, DirectX::SimpleMath::Vector3 pos, float dir)
	//{
	//	// i番目の角度を設定
	//	m_tWall->SetDir(XMConvertToRadians(dir));
	//	// i番目の座標を設定
	//	m_tWall->SetPosition(pos);
	//}
#pragma endregion


/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime"></param>
/// <returns></returns>
bool ModelManager::Update(float elapsedTime)
{
	//if (m_oniNum == 1)
	//{
	//	m_player->SetOniFlag(true);
	//}
	//else if (m_oniNum == 2)
	//{
	//	m_player->SetOniFlag(false);
	//}

	/*-------Plaerオブジェクトの更新---------*/
	PlayerControl();				// プレイヤーの操作入力
	//m_player->Update(elapsedTime);	// プレイヤーの更新

	/*-------ボールオブジェクトの更新---------*/
	// 発射されていない時
	//if (m_ball->GetShotFlag() == false)
	//{
	//	// プレイヤーが鬼の時
	//	if (m_oniNum == 1)
	//	{
	//		m_ball->SetPosition(m_player->GetPosition().x, m_player->GetPosition().y + 0.5f, m_player->GetPosition().z);
	//	}
		// cpuが鬼の時
		//if (m_oniNum == 2)
		//{
		//	m_ball->SetPosition(m_cpu->GetPosition().x, m_cpu->GetPosition().y + 0.5f, m_cpu->GetPosition().z);
		//}
	//}
	//m_ball->Update(elapsedTime);	// ボールの更新
	//　当たり判定処理をまとめた関数
	//HitManagement();
	return true;
}
#pragma region HitManagement
/// <summary>
/// 当たり判定の管理
/// </summary>
/// <param name="player">プレイヤー</param>
/// <param name="cpu">コンピュータ</param>
/// <param name="wall">板状の壁</param>
void ModelManager::HitManagement()
{
	// playerが鬼なら
	//if (m_oniNum == 1) {
	//	if (Collision::HitCheck_Sphere2Sphere(m_ball->GetCollision(), m_cpu->GetCollision()) == true)
	//	{
	//		m_ball->SetShotFlag(false);
	//		m_ball->ResetVel(Vector3::Zero);				// 速度を初期化
	//		m_ball->SetRotation(Quaternion::Identity);		// 角度を初期化
	//		m_ball->SetPosition(m_cpu->GetPosition().x, m_cpu->GetPosition().y + 0.3f, m_cpu->GetPosition().z);	// ボールにプレイヤーの座標を与える
	//		m_ball->SetRotation(m_cpu->GetRotation());	// ボールにプレイヤーの角度を与える
	//		m_ball->SetVel(m_cpu->GetVel());				// ボールにプレイヤーの速度を与える
	//		m_ball->SetPosition(m_cpu->GetPosition().x, m_cpu->GetPosition().y + 0.3f, m_cpu->GetPosition().z);
	//		m_oniNum = 2;
	//	}
	//}

	// ボールと壁の当たり判定
	//for (int i = 0; i < NUM_BOARDW_WALL; i++)
	//{
	//	if (Collision::HitCheck_Sphere2Box(m_ball->GetCollision(), m_boardWall[i]->GetCollision()) == true)
	//	{
	//		// playerが鬼なら
	//		if (m_oniNum == 1)
	//		{
	//			m_ball->ResetVel(Vector3::Zero);				// 速度を初期化
	//			m_ball->SetRotation(Quaternion::Identity);		// 角度を初期化
	//			m_ball->SetPosition(m_player->GetPosition().x, m_player->GetPosition().y + 0.3f, m_player->GetPosition().z);	// ボールにプレイヤーの座標を与える
	//			m_ball->SetRotation(m_player->GetRotation());	// ボールにプレイヤーの角度を与える
	//			m_ball->SetVel(m_player->GetVel());				// ボールにプレイヤーの速度を与える
	//			m_ball->SetShotFlag(false);
	//		}
	//		//cpuが鬼なら
	//		//if (m_oniNum == 2)
	//		//{
	//		//	m_ball->ResetVel(Vector3::Zero);				// 速度を初期化
	//		//	m_ball->SetRotation(Quaternion::Identity);		// 角度を初期化
	//		//	m_ball->SetPosition(m_cpu->GetPosition().x, m_cpu->GetPosition().y + 0.3f, m_cpu->GetPosition().z);	// ボールにプレイヤーの座標を与える
	//		//	m_ball->SetRotation(m_cpu->GetRotation());	// ボールにプレイヤーの角度を与える
	//		//	m_ball->SetVel(m_cpu->GetVel());				// ボールにプレイヤーの速度を与える
	//		//	m_ball->SetPosition(m_cpu->GetPosition().x, m_cpu->GetPosition().y + 0.3f, m_cpu->GetPosition().z);
	//		//	m_ball->SetShotFlag(false);
	//		//}
	//	}
	//}
	/*if (Collision::HitCheck_Sphere2Box(player->GetCollision(), bWall->GetCollision()) == true)
	{
	}
	if (Collision::HitCheck_Sphere2Box(cpu->GetCollision(), bWall->GetCollision()) == true)
	{
	}*/

	//Vector3 playerPos = m_player->GetPosition();
	//Vector3 playerVel = m_player->GetVel();
	//Vector3 playerVelocity[2] =
	//{
	//	Vector3(playerPos.x + 5,playerPos.y,playerPos.z + 5) - playerVel,
	//	Vector3(playerPos.x + 5,playerPos.y,playerPos.z + 5) + playerVel
	//};

	// プレイヤーと板状の壁の当たり判定
	// z軸が固定で並べられた壁
	//(z軸が+値の壁[0 ～ 7],z軸が-値の壁[8 ～ 15])
	//for (int zWall = 0; zWall < 16; zWall++)
	//{
	//		// 当たり判定がヒット
	//	if (Collision::HitCheck_Sphere2Box(m_player->GetCollision(), m_boardWall[zWall]->GetCollision()) == true)
	//	{
	//		// 当たった時のプレイヤーの座標
	//		Vector3 pPos = m_player->GetPosition();
	//		// 当てられた壁の座標
	//		Vector3 wPos = m_boardWall[zWall]->GetPosition();

	//		// 壁の中心ｚ軸から幅0.05fよりもプレイヤーのｚ軸が超えていたら
	//		if (wPos.z - 0.05f > pPos.z)
	//		{
	//			pPos = Vector3(pPos.x, pPos.y, wPos.z - 0.8f);
	//			m_player->SetPosition(pPos);
	//		}
	//		else if (wPos.z + 0.05f < pPos.z)
	//		{
	//			pPos = Vector3(pPos.x, pPos.y, wPos.z + 0.8f);
	//			m_player->SetPosition(pPos);
	//		}
	//	}
	//}
	//// x軸が固定で並べられた壁
	////(x軸が+値の壁[16 ～ 23],x軸が-値の壁[24 ～ 31])
	//for (int xWall = 16; xWall < 32; xWall++)
	//{
	//	// 当たり判定がヒット
	//	if (Collision::HitCheck_Sphere2Box(m_player->GetCollision(), m_boardWall[xWall]->GetCollision()) == true)
	//	{
	//		// 当たった時のプレイヤーの座標
	//		Vector3 pPos = m_player->GetPosition();
	//		// 当てられた壁の座標
	//		Vector3 wPos = m_boardWall[xWall]->GetPosition();

	//		// 壁の中心x軸から幅0.1fよりもプレイヤーのx軸が超えていたら
	//		if (wPos.x - 0.05f < pPos.x)
	//		{
	//			pPos = Vector3(wPos.x + 0.8f, pPos.y, pPos.z);
	//			m_player->SetPosition(pPos);
	//		}
	//		else
	//		if (wPos.x + 0.05f > pPos.x)
	//		{
	//			pPos = Vector3(wPos.x - 0.8f, pPos.y, pPos.z);
	//			m_player->SetPosition(pPos);
	//		}

	//	}
	//}
}
#pragma endregion
#pragma region Control
// プレイヤーの操作
void ModelManager::PlayerControl()
{
	//// キー入力
	//Keyboard::State kb = Keyboard::Get().GetState();
	//// トリガー
	//m_tracker.Update(kb);

	//// ボールが発射されていない時
	//if (m_ball->GetShotFlag() == false)
	//{
	//	// Eキーが押された時
	//	if (m_tracker.pressed.E)
	//	{
	//		// 鬼がプレイヤーなら
	//		if (m_oniNum == 1)
	//		{
	//			//m_ball->ResetVel(Vector3::Zero);				// 速度を初期化
	//			//m_ball->SetRotation(Quaternion::Identity);		// 角度を初期化
	//			//m_ball->SetPosition(m_player->GetPosition());	// ボールにプレイヤーの座標を与える
	//			//m_ball->SetRotation(m_player->GetRotation());	// ボールにプレイヤーの角度を与える
	//			//m_ball->SetVel(m_player->GetVel());				// ボールにプレイヤーの速度を与える
	//			//m_ball->SetShotFlag(true);						// ボールを発射する
	//		}
	//	}
	//}

	//// Ｑキーと上下移動するキーが同時に押されている時
	//if ((kb.Q) && ((kb.Up) || (kb.Down) || (kb.I) || (kb.K)))
	//{
	//	// スタミナゲージがある時
	//	if (m_stamina >= 0) {
	//		m_stamina--;
	//		m_player->SetDash(true);	// プレイヤーのフラグを変更する関数にtrueを伝える
	//									// スタミナが無い(0)の時
	//		if (m_stamina <= 0)
	//		{
	//			// プレイヤーのダッシュフラグをfalse
	//			m_player->SetDash(false);
	//		}
	//	}
	//}
	//else
	//{
	//	// スタミナゲージが減っている時
	//	if (m_stamina <= 200) {
	//		m_stamina++;				// スタミナを回復
	//		m_player->SetDash(false);	// プレイヤーのフラグを変更する関数にtrueを伝える
	//	}
	//}

	//// 前移動
	//if ((kb.Up) || (kb.I))
	//{
	//	m_player->Move(Player::FORWARD);
	//}
	//// 後ろ移動
	//if ((kb.Down) || (kb.K))
	//{
	//	m_player->Move(Player::BACK);
	//}
	//// 左移動
	//if ((kb.Left) || (kb.J))
	//{
	//	m_player->Move(Player::LEFT_TURN);
	//}
	//// 右移動
	//if ((kb.Right) || (kb.L))
	//{
	//	m_player->Move(Player::RIGHT_TURN);
	//}

	//// 左斜め前移動
	//if (((kb.Up) && (kb.Left)) || ((kb.I) && (kb.J)))
	//{
	//	m_player->Move(Player::FORWARD_LEFT);
	//}
	//// 右斜め前移動
	//if (((kb.Up) && (kb.Right)) || ((kb.I) && (kb.L)))
	//{
	//	m_player->Move(Player::FORWARD_RIGHT);
	//}
	//// 左斜め後ろ移動
	//if (((kb.Down) && (kb.Left)) || ((kb.K) && (kb.J)))
	//{
	//	m_player->Move(Player::BACK_LEFT);
	//}
	//// 右斜め後ろ移動
	//if (((kb.Down) && (kb.Right)) || ((kb.K) && (kb.L)))
	//{
	//	m_player->Move(Player::BACK_RIGHT);
	//}
}
#pragma endregion


/// <summary>
/// 作成したモデルを描画
/// </summary>
/// <param name="view">ビュー行列</param>
/// <param name="projection">射影行列</param>
void ModelManager::Render(DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix projection)
{
	//m_camera.PlayCamera(m_player->GetPosition(),m_player->GetDir());
	//m_player->Render(m_states, view, projection);
	//m_ball->Render(m_states, view, projection);
}


/// <summary>
/// 解放関数
/// </summary>
void ModelManager::Finalize()
{
	delete m_player;
	delete m_ball;
	delete m_states;
}