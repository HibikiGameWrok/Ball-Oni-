#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class CountDownUI : public Task::TaskBase
{
public:
	const float MAX_COUNTDOWNUI_SIZE = 6.0f;	// カウントダウンするUIの全体サイズ

	const float COUNTUI_WIDTH = 100.0f;		// 3秒カウントダウンするUIの幅	

	const int TimeUI_WIDTH = 20;	// 画像の１つの数字分の幅
	const int TimeUI_HEIGHT = 40;	// 画像の１つの数字分の高さ
private:
	System::DrawData m_imageCountDownUI;
	
	int m_countTime; // カウントタイム

	DirectX::SimpleMath::Vector4 m_countDown_rect;  // カウントダウンUIの画像範囲
	DirectX::SimpleMath::Vector2 m_countDown_scale;	// カウントダウンUIの大きさを変動させる変数

public:
	// コンストラクタ
	CountDownUI();
	// デストラクタ
	~CountDownUI();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);

	// 描画
	void Draw();

	// 画像の挙動処理
	void ImageMove();
};
