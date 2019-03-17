#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class GameTime : public Task::TaskBase
{
public:
	const int MAX_FRAME_TIME = 60;	// 最大のフレームタイム

	const int TIME_UI_WIDTH = 20;	// 画像の１つの数字分の幅
	const int TIME_UI_HEIGHT = 40;	// 画像の１つの数字分の高さ
	
private:
	System::DrawData m_backGround;	// 背景
	System::DrawData m_onePlace;		// フレーム単位画像
	System::DrawData m_tenPlace;		// 秒単位画像
	System::DrawData m_finishUI;		// 終了を知らせるUI

	bool m_stopFlag; // カウントが止まっているか判断するフラグ
	bool m_finishFlag;	// 終了フラグ

	int m_framesTime;  // フレーム単位 カウント用変数
	int m_secondsTime; // 秒単位	   カウント用変数

public:
	// コンストラクタ
	GameTime();
	// デストラクタ
	~GameTime();

	// 初期化
	void Start();

	// 更新処理
	bool Update(float elapsedTime);

	// 描画
	void Draw();

	// タイムのカウントダウン処理
	void Count_Time();


public:
	// フレームカウントを取得
	int GetFrameTime() { return m_framesTime; }
	// 秒を取得
	int GetSecondsTime() { return m_secondsTime; }
	
	// カウントを止めるフラグ
	bool GetStopFlag() { return m_stopFlag; }
	// 終了フラグを設定
	void SetStopFlag(bool stop) { m_stopFlag = stop; }

	// 終了フラグを取得
	bool GetFinishFlag() { return m_finishFlag; }
};

