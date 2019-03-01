#include "../../pch.h"
#include "../../Control/keyboard_control.h"
#include "StaminaBer.h"

using namespace DirectX;
using namespace System;

/// <summary>
/// コンストラクタ
/// </summary>
StaminaGauge::StaminaGauge()
	:m_staminaValue(MAX_STAMINA)
	, m_animationRect(0)
	, m_animationTime(0)
	, m_gaugeZeroFlag(false)
{
}

/// <summary>
/// デストラクタ
/// </summary>
StaminaGauge::~StaminaGauge()
{
}


/// <summary>
/// 初期化
/// </summary>
void StaminaGauge::Start()
{
	// スタミナゲージの背景
	System::DrawManager::GetInstance().LoadTexture(m_backStaminaGauge, L"Resources\\Textures\\PlayScene\\BackStaminaGauge.png");
	m_backStaminaGauge.SetRect(MAX_STAMINA, IMAGE_WIDTH);
	m_backStaminaGauge.SetPos(0, 30);

	// スタミナ―ゲージ
	System::DrawManager::GetInstance().LoadTexture(m_staminaGauge, L"Resources\\Textures\\PlayScene\\StaminaGauge.png");
	m_staminaGauge.SetRect(m_staminaValue, IMAGE_WIDTH);
	m_staminaGauge.SetPos(0, 30);

	// スタミナの名前
	System::DrawManager::GetInstance().LoadTexture(m_uiName, L"Resources\\Textures\\PlayScene\\stamina_name.png");
	m_uiName.SetRect(120, IMAGE_WIDTH);
	m_uiName.SetPos(0,0);
}


/// <summary>
/// 更新
/// </summary>
/// <returns>終了状態</returns>
bool StaminaGauge::Update(float elapsedTime)
{
	// フレーム数が定数になるまでカウントを進める
	if (m_animationTime < MAX_ANIME_FRAME) {
		m_animationTime++;
	}
	// フレーム数が定数になったらアニメーションを進める
	if (m_animationTime == MAX_ANIME_FRAME){
		if (m_animationRect < MAX_RECT_Y) {
			m_animationRect += IMAGE_WIDTH;
		}
		m_animationTime = 0;
	}

	// アニメーション画像が画像全体の最大値に達したら
	if (m_animationRect == MAX_RECT_Y){
		// 元に戻す
		m_animationRect = 0;
	}
	

	// 走るフラグがtrueの時
	if (m_dashFlag == true)
	{
		// スタミナがある時
		if (m_staminaValue >= 0)
		{
			m_staminaValue -= 3;	 // スタミナを減らす
			m_gaugeZeroFlag = true;
		}
	}
	else 
	if (m_dashFlag == false)	// ダッシュしていない時
	{
		// スタミナが最大値よりも少ない時
		if (m_staminaValue <= MAX_STAMINA)
		{
			m_staminaValue += 1; // スタミナを回復
			m_gaugeZeroFlag = false;
		}
	}

	// スタミナがない時
	if (m_staminaValue <= 0)
	{
		m_gaugeZeroFlag = false;
	}
	
	m_staminaGauge.SetRect(0,m_animationRect,m_staminaValue, m_animationRect + IMAGE_WIDTH);
	return true; // falseを返すとタスクは消える
}




/// <summary>
/// 描画
/// </summary>
void StaminaGauge::Draw()
{
	System::DrawManager::GetInstance().Draw(m_backStaminaGauge);
	System::DrawManager::GetInstance().Draw(m_staminaGauge);
	System::DrawManager::GetInstance().Draw(m_uiName);
}

