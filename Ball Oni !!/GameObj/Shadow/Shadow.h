//
//	File	 : Shadow.h
//
//  Contents : TaskBaseを継承したShadowクラス
//
//	name	 : Hibiki Yoshiyasu
//
#pragma once
#include "../../Data/Draw3DData.h"
#include "../../Manager/Draw3DManager.h"
#include "../../DeviceResources.h"

class Shadow : public Draw3DData
{
public:
	// コンストラクタ
	Shadow();
	Shadow(DirectX::SimpleMath::Vector3 pos);

	// デストラクタ
	~Shadow();

	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime);

	// 描画
	void Draw() override;
};