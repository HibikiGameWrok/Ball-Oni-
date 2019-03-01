#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class PleaseSpaceUI : public Task::TaskBase
{
public:
	// コンストラクタ
	PleaseSpaceUI(DirectX::SimpleMath::Vector2 pos);
	// デストラクタ
	~PleaseSpaceUI();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);

	// 描画
	void Draw();

	void Change();

private:
	System::DrawData m_imagePleaseSpaceUI;
	int m_frameTime;
	bool m_flashingImage;
	DirectX::SimpleMath::Vector2 m_pos;
};