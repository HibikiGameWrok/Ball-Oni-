//
//	File	 : Floor.h
//
//  Contents : Floorのモデルを表示するクラス
//
//	name	 : Hibiki Yoshiyasu
//
#pragma once
#include "../../Data/Draw3DData.h"
#include "../../Manager/Draw3DManager.h"

class Floor : public Draw3DData
{
public:
	// コンストラクタ
	Floor();

	// デストラクタ
	~Floor();

	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime) override;
	
	// 描画
	void Draw() override;
};