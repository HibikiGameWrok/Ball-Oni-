#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class StaminaGauge : public Task::TaskBase
{
private:
	const int MAX_STAMINA = 200;
	const int MAX_RECT_Y = 270;			// アニメーション用画像範囲の最大値
	const int IMAGE_WIDTH = 30;			// 画像の幅
	const int MAX_ANIME_FRAME = 10;		// アニメーション用フレームタイム

	System::DrawData m_backStaminaGauge;	// スタミナバーの背景
	System::DrawData m_staminaGauge;		// 変動するゲージ画像
	System::DrawData m_uiName;			// UIの名前

	int m_staminaValue;	 // バーの値
	int m_animationRect; // アニメーション用画像範囲変動変数 
	int m_animationTime; // アニメタイム

	bool m_dashFlag;	 // ダッシュフラグ
	bool m_gaugeZeroFlag;	 // スタミナがないかのフラグ
public:
	// コンストラクタ
	StaminaGauge();
	// デストラクタ
	~StaminaGauge();

	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw() override;

public:
	// バーの値があるかどうかのフラグを設定または取得関数
	void SetBerZeroFlag(bool flag) { m_gaugeZeroFlag = flag; }
	bool GetBerZeroFlag(){ return m_gaugeZeroFlag; }

	// ダッシュフラグを受け取る
	void SetDashFlag(bool on) { m_dashFlag = on; }
	bool GetDashFlag() { return m_dashFlag; }
};
