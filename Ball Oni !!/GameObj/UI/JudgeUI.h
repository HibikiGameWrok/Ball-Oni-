//
//	File	 : JudgeUI.h
//
//  Contents : 誰が鬼なのかを知らせるUIを描画する
//
//	name	 : Hibiki Yoshiyasu
//
#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class JudgeUI : public Task::TaskBase
{
private:
	System::DrawData m_judgePlayer;	// プレイヤーが鬼の時に描画するUI
	System::DrawData m_judgeCpu;	// CPUが鬼の時に描画するUI

	// 表示するUIのファイルパス
	const wchar_t* mp_FileNamePlayer;
	const wchar_t* mp_FileNameCpu;

	unsigned __int8 m_numChara;		// キャラクターの番号

	float m_uiScale[2];

	int m_framesTime;  // フレーム単位 カウント用変数
	int m_secondsTime; // 秒単位	   カウント用変数

	bool m_moveUIFlag;

public:
	// コンストラクタ
	JudgeUI();
	// デストラクタ
	~JudgeUI();

	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw();

	// 鬼を設定する
	void SetNowOni(unsigned __int8 num);
	// 誰が鬼かを取得する
	unsigned __int8 GetNowOni ();

	//
	void SetMoveUI(bool flag) { m_moveUIFlag = flag; }
	// 
	bool GetMoveUI() { return m_moveUIFlag; }
};