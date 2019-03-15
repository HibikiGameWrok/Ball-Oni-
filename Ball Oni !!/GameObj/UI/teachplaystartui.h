#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class TeachPlayStartUI : public Task::TaskBase
{
private:
	System::DrawData m_imageTeachPlayStartUI;

public:
	// コンストラクタ
	TeachPlayStartUI();
	// デストラクタ
	~TeachPlayStartUI();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);

	// 描画
	void Draw();
};