//
//	SkyBox.h
//  
//　四角形の背景オブジェクト、タスクベース継承
//
#pragma once
#include "../../Data/Draw3DData.h"
#include "../../Manager/Draw3DManager.h"

class SkyBox : public Draw3DData
{
public:
	// コンストラクタ
	SkyBox();

	// デストラクタ
	~SkyBox();

	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime) override;

	// 描画
	void Draw() override;
};