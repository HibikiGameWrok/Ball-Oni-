#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class ResultBackGround : public Task::TaskBase
{
public:
	// コンストラクタ
	ResultBackGround();
	// デストラクタ
	~ResultBackGround();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw();

private:
	System::DrawData m_backGound;
	const wchar_t* mp_FileName;

};