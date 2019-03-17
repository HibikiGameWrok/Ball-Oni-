#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class CountDownUI : public Task::TaskBase
{
public:
	const int MAX_COUNT = 3;

	const float MAX_COUNTDOWNUI_SIZE = 6.0f;	// カウントダウンするUIの全体サイズ

	const float ZERO_SCALE = 0.0f;	// scaleが0の定数

	const float SMALL_DOWN = 0.1f;  // 小さくする数値 

	const float COUNTUI_WIDTH = 100.0f;		// 3秒カウントダウンするUIの幅	
private:
	System::DrawData m_imageCountDownUI;
	
	int m_frameTime; // フレームタイム
	int m_countTime; // カウントタイム

	DirectX::SimpleMath::Vector2 m_pos;	// 描画座標
	DirectX::SimpleMath::Vector4 m_countDown_rect;  // カウントダウンUIの画像範囲
	DirectX::SimpleMath::Vector2 m_countDown_scale;	// カウントダウンUIの大きさを変動させる変数

	bool m_moveFlag;  // UIが動作中か判断するフラグ

public:
	// コンストラクタ
	CountDownUI();
	CountDownUI(DirectX::SimpleMath::Vector2 pos);
	// デストラクタ
	~CountDownUI();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);

	// 描画
	void Draw();

	// カウントダウン処理
	void CountDownFunc();

	// 画像の挙動処理
	void ImageMove();
public:
	// 動作フラグを取得＆設定する関数
	bool GetMoveFlag() { return m_moveFlag; }
	void SetMoveFlag(bool moveFlag) { m_moveFlag = moveFlag; }

	// 描画座標を設定する関数
	void SetPos(DirectX::SimpleMath::Vector2 pos) { m_pos = pos; }
};
