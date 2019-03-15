#include "CountDownUI.h"

/// <summary>
/// コンストラクタ
/// </summary>
CountDownUI::CountDownUI()
	:m_countDown_rect(0,0,100,100)
	,m_countDown_scale(MAX_COUNTDOWNUI_SIZE)
{
}

/// <summary>
/// デストラクタ
/// </summary>
CountDownUI::~CountDownUI()
{
}

/// <summary>
/// 開始処理
/// </summary>
void CountDownUI::Start()
{
	// カウントダウンするUI
	System::DrawManager::GetInstance().LoadTexture(m_imageCountDownUI, L"Resources\\Textures\\PlayScene\\CountDown.png");
	m_imageCountDownUI.SetRect(
		static_cast<LONG>(m_countDown_rect.x),
		static_cast<LONG>(m_countDown_rect.y),
		static_cast<LONG>(m_countDown_rect.z),
		static_cast<LONG>(m_countDown_rect.w)
	);
	m_imageCountDownUI.SetOrigin(100 / 2, 100 / 2);
	m_imageCountDownUI.SetPos(800 / 2, 600 / 2);
	m_imageCountDownUI.SetScale(m_countDown_scale.x, m_countDown_scale.y);
}

/// <summary>
/// 更新処理
/// </summary>
/// <returns>true == 更新, false == 停止 </returns>
bool CountDownUI::Update(float elapsedTime)
{
	// 毎フレーム大きさと画像サイズを更新
	m_imageCountDownUI.SetScale(m_countDown_scale.x, m_countDown_scale.y);
	m_imageCountDownUI.SetRect(
		static_cast<LONG>(m_countDown_rect.x),
		static_cast<LONG>(m_countDown_rect.y),
		static_cast<LONG>(m_countDown_rect.z),
		static_cast<LONG>(m_countDown_rect.w)
	);
	return true;
}

/// <summary>
/// 描画処理
/// </summary>
void CountDownUI::Draw()
{
	if ((m_countTime <= 3 && m_countTime >= 1) && m_countTime > 0)
	{
		System::DrawManager::GetInstance().Draw(m_imageCountDownUI);
	}
}

/// <summary>
/// 画像の挙動処理
/// </summary>
void CountDownUI::ImageMove()
{
	// 画像スケールが0になった時大きい状態に戻す
	if (m_countDown_scale.x <= 0.0f)
	{
		m_countDown_scale.x = MAX_COUNTDOWNUI_SIZE;
		m_countDown_scale.y = MAX_COUNTDOWNUI_SIZE;
	}

	// 残り３秒の時
	if (m_countTime == 3)
	{
		// 画像スケールを縮小
		if (m_countDown_scale.x > 0 || m_countDown_scale.y > 0)
		{
			m_countDown_scale.x -= 0.1f;
			m_countDown_scale.y -= 0.1f;
		}
	}
	// 残り２秒の時
	if (m_countTime == 2)
	{
		m_countDown_rect.x = COUNTUI_WIDTH;
		m_countDown_rect.y = 0;
		m_countDown_rect.z = COUNTUI_WIDTH * 2;
		m_countDown_rect.w = COUNTUI_WIDTH;
		// 画像スケールを縮小
		if (m_countDown_scale.x > 0 || m_countDown_scale.y > 0)
		{
			m_countDown_scale.x -= 0.1f;
			m_countDown_scale.y -= 0.1f;
		}
	}
	// 残り１秒の時
	if (m_countTime == 1)
	{
		m_countDown_rect.x = COUNTUI_WIDTH * 2;
		m_countDown_rect.y = 0;
		m_countDown_rect.z = COUNTUI_WIDTH * 3;
		m_countDown_rect.w = COUNTUI_WIDTH;
		// 画像スケールを縮小
		if (m_countDown_scale.x > 0 || m_countDown_scale.y > 0)
		{
			m_countDown_scale.x -= 0.1f;
			m_countDown_scale.y -= 0.1f;
		}
	}
}
