#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class TitleName : public Task::TaskBase
{
public:
	// コンストラクタ
	TitleName();
	// デストラクタ
	~TitleName();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);
	
	// 描画
	void Draw();

private:
	System::DrawData m_imageTitel;

};