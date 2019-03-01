//
//	File	 : BoardWall.h
//
//  Contents : CollisionBoxを継承したBoardWallクラス
//
//	name	 : Hibiki Yoshiyasu
//
#pragma once
#include "../../Collision/CollisionBox.h"
#include "../../Manager/Draw3DManager.h"
#include "../../../StepTimer.h"
class BoardWall : public CollisionBox
{
public:
	// コンストラクタ
	BoardWall();
	BoardWall(DirectX::SimpleMath::Vector3 pos, float dir);
	BoardWall(DirectX::SimpleMath::Vector3 pos, float dir,DirectX::SimpleMath::Vector3 boxRadius);
	// デストラクタ
	~BoardWall();


	// 初期化
	void Start() override;
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw() override;

public:
	// 当たり判定の設定
	void SetColWall(DirectX::SimpleMath::Vector3 boxCol);
};
