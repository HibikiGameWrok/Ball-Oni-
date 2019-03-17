//
//	File	 : GameTime.cpp
//
//  Contents : プレイ中のタイム管理と描画
//
//	name	 : Hibiki Yoshiyasu
//
#pragma once
#include "GameTime.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
GameTime::GameTime()
	:m_stopFlag(true)
	,m_finishFlag(false)
	,m_framesTime(60)
	,m_secondsTime(60)
{
}

/// <summary>
/// デストラクタ
/// </summary>
GameTime::~GameTime()
{
}

/// <summary>
/// 開始処理
/// </summary>
void GameTime::Start()
{
	// タイムの背景
	System::DrawManager::GetInstance().LoadTexture(m_backGround, L"Resources\\Textures\\PlayScene\\Time_Back.png");
	m_backGround.SetRect(40, 40);
	m_backGround.SetPos(390, 0);

	// フレーム数
	System::DrawManager::GetInstance().LoadTexture(m_onePlace, L"Resources\\Textures\\PlayScene\\time.png");
	m_onePlace.SetRect(m_secondsTime / 10 * TIME_UI_WIDTH,0, m_secondsTime / 10 * TIME_UI_WIDTH + TIME_UI_WIDTH, TIME_UI_HEIGHT);
	m_onePlace.SetPos(390, 0);

	// 秒数
	System::DrawManager::GetInstance().LoadTexture(m_tenPlace, L"Resources\\Textures\\PlayScene\\time.png");
	m_tenPlace.SetRect(m_secondsTime % 10 * TIME_UI_WIDTH,0, m_secondsTime % 10 * TIME_UI_WIDTH + TIME_UI_WIDTH, TIME_UI_HEIGHT);
	m_tenPlace.SetPos(410, 0);

	// 終了画像
	System::DrawManager::GetInstance().LoadTexture(m_finishUI, L"Resources\\Textures\\PlayScene\\Finish.png");
	m_finishUI.SetRect(250,150);
	m_finishUI.SetOrigin(250 / 2, 150 / 2);
	m_finishUI.SetPos(800 / 2, 600 / 2);
}

/// <summary>
/// 更新処理
/// </summary>
/// <returns>true == 更新, false == 停止 </returns>
bool GameTime::Update(float elapsedTime)
{
	// ストップされていなければ
	if (m_stopFlag != true)
	{
		// タイム処理
		Count_Time();
	}

	// 1桁目の表示範囲を設定
	m_onePlace.SetRect(m_secondsTime / 10 * TIME_UI_WIDTH, 0, m_secondsTime / 10 * TIME_UI_WIDTH + TIME_UI_WIDTH, TIME_UI_HEIGHT);
	// 10桁目の表示範囲を設定
	m_tenPlace.SetRect(m_secondsTime % 10 * TIME_UI_WIDTH, 0, m_secondsTime % 10 * TIME_UI_WIDTH + TIME_UI_WIDTH, TIME_UI_HEIGHT);
	return true;
}

/// <summary>
/// 描画処理
/// </summary>
void GameTime::Draw()
{
	// 背景
	System::DrawManager::GetInstance().Draw(m_backGround);

	// 1の位
	System::DrawManager::GetInstance().Draw(m_onePlace);
	// 10の位
	System::DrawManager::GetInstance().Draw(m_tenPlace);
	
	// 終了
	if (m_secondsTime == 0)
	{
		System::DrawManager::GetInstance().Draw(m_finishUI);
	}
}

/// <summary>
/// タイムのカウント処理
/// </summary>
void GameTime::Count_Time()
{
		// フレーム単位変数を0になるまでカウントダウン
		if (m_secondsTime != 0) {
			if (m_framesTime >= 0) {
				m_framesTime--;
			}
		}

		// フレーム単位変数が0になったら秒単位変数を1秒分カウントダウン 
		if (m_framesTime < 0) {
			m_secondsTime--;
			m_framesTime = MAX_FRAME_TIME;
		}

		// 秒数が0になった時終了を知らせる
		if (m_secondsTime == 0)
		{
			m_finishFlag = true;
		}
}

