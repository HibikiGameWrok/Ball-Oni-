#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class StartSignUI : public Task::TaskBase
{
private:
	System::DrawData m_imageStartSignUI;

public:
	// コンストラクタ
	StartSignUI();
	// デストラクタ
	~StartSignUI();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);

	// 描画
	void Draw();
};