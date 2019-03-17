#include "CountDownUI.h"

/// <summary>
/// コンストラクタ
/// </summary>
CountDownUI::CountDownUI()
	:m_frameTime(0)
	,m_countTime(MAX_COUNT)
	,m_countDown_rect(0,0,100,100)
	,m_countDown_scale(MAX_COUNTDOWNUI_SIZE)
	,m_moveFlag(false)
{
}

/// <summary>
/// 引数ありコンストラクタ
/// </summary>
/// <param name="pos">描画座標</param>
CountDownUI::CountDownUI(DirectX::SimpleMath::Vector2 pos)
	:m_frameTime(0)
	, m_countTime(MAX_COUNT)
	, m_countDown_rect(0, 0, 100, 100)
	, m_countDown_scale(MAX_COUNTDOWNUI_SIZE)
	, m_moveFlag(true)
{
	m_pos = pos;
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
	// 画像の表示範囲を設定
	m_imageCountDownUI.SetRect(
		static_cast<LONG>(m_countDown_rect.x),
		static_cast<LONG>(m_countDown_rect.y),
		static_cast<LONG>(m_countDown_rect.z),
		static_cast<LONG>(m_countDown_rect.w)
	);

	// 画像の中心点を設定
	m_imageCountDownUI.SetOrigin(100 / 2, 100 / 2);
	// 画像の座標を設定
	m_imageCountDownUI.SetPos(m_pos.x, m_pos.y);
	// 画像の全体サイズの設定
	m_imageCountDownUI.SetScale(m_countDown_scale.x, m_countDown_scale.y);
}

/// <summary>
/// 更新処理
/// </summary>
/// <returns>true == 更新, false == 停止 </returns>
bool CountDownUI::Update(float elapsedTime)
{
	// 画像の座標を更新
	m_imageCountDownUI.SetPos(m_pos.x, m_pos.y);

	// 動作フラグがtrueの時
	if (m_moveFlag == true)
	{
		CountDownFunc();
	}
	else
	{
		// 初期化
		m_frameTime = 0;
		m_countTime = MAX_COUNT;
	}

	// 画像の挙動処理
	ImageMove();

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
	// ３～１の間に描画をし続ける
	if (m_moveFlag == true && ((m_countTime <= 3 && m_countTime >= 1) && m_countTime > 0))
	{
		System::DrawManager::GetInstance().Draw(m_imageCountDownUI);
	}
}

/// <summary>
/// カウントダウン処理
/// </summary>
void CountDownUI::CountDownFunc()
{
	// フレームタイムを60fになるまで加算
	m_frameTime += 1;
	if (m_frameTime >= 60)
	{
		// 1秒引く
		m_countTime -= 1;
		// 初期化
		m_frameTime = 0;
	}

	if (m_countTime <= 0)
	{
		m_moveFlag = false;
	}
}

/// <summary>
/// 画像の挙動処理
/// </summary>
void CountDownUI::ImageMove()
{
	// 画像スケールが0になった時大きい状態に戻す
	if (m_countDown_scale.x <= ZERO_SCALE)
	{
		m_countDown_scale.x = MAX_COUNTDOWNUI_SIZE;
		m_countDown_scale.y = MAX_COUNTDOWNUI_SIZE;
	}

	// 残り３秒の時
	if (m_countTime == 3)
	{
		m_countDown_rect.x = 0;
		m_countDown_rect.y = 0;
		m_countDown_rect.z = COUNTUI_WIDTH;
		m_countDown_rect.w = COUNTUI_WIDTH;
		// 画像スケールを縮小
		if (m_countDown_scale.x > ZERO_SCALE || m_countDown_scale.y > ZERO_SCALE)
		{
			m_countDown_scale.x -= SMALL_DOWN;
			m_countDown_scale.y -= SMALL_DOWN;
		}
	}

	// 残り２秒の時
	if (m_countTime == 2)
	{
		// 描画範囲をずらす
		m_countDown_rect.x = COUNTUI_WIDTH;
		m_countDown_rect.y = 0;
		m_countDown_rect.z = COUNTUI_WIDTH * 2;
		m_countDown_rect.w = COUNTUI_WIDTH;
		// 画像スケールを縮小
		if (m_countDown_scale.x > ZERO_SCALE || m_countDown_scale.y > ZERO_SCALE)
		{
			m_countDown_scale.x -= SMALL_DOWN;
			m_countDown_scale.y -= SMALL_DOWN;
		}
	}

	// 残り１秒の時
	if (m_countTime == 1)
	{
		// 描画範囲をずらす
		m_countDown_rect.x = COUNTUI_WIDTH * 2;
		m_countDown_rect.y = 0;
		m_countDown_rect.z = COUNTUI_WIDTH * 3;
		m_countDown_rect.w = COUNTUI_WIDTH;
		// 画像スケールを縮小
		if (m_countDown_scale.x > ZERO_SCALE || m_countDown_scale.y > ZERO_SCALE)
		{
			m_countDown_scale.x -= SMALL_DOWN;
			m_countDown_scale.y -= SMALL_DOWN;
		}
	}
}
