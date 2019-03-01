#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class TitleBackGround : public Task::TaskBase
{
public:
	// コンストラクタ
	TitleBackGround();
	// デストラクタ
	~TitleBackGround();

	// 初期化
	void Start();
	// 更新処理
	bool Update();
	bool Update(DX::StepTimer timer);
	// 描画
	void Draw();

private:
	System::DrawData m_imageBackGround;

};