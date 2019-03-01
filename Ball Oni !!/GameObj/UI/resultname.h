#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class ResultName : public Task::TaskBase
{
public:
	// コンストラクタ
	ResultName();
	// デストラクタ
	~ResultName();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw();

private:
	System::DrawData m_image;
	const wchar_t* mp_FileName;

};