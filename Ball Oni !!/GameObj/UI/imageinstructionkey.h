#pragma once
#include "../../pch.h"
#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class InstructionKey : public Task::TaskBase
{
public:
	// コンストラクタ
	InstructionKey();
	// デストラクタ
	~InstructionKey();
	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw();
private:
	System::DrawData m_arrowKey;	// 十字キー
	System::DrawData m_dashKey;		// 走るキー
	System::DrawData m_shotKey;		// 玉を投げるキー
};