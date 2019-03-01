#pragma once
#include "../../pch.h"
#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class KeyOperation : public Task::TaskBase
{
public:
	enum KEY_FLAG
	{
		STOP,
		FORWARD,	// 前進
		BACK,		// 後退
		RIGHT_TURN,	// 右旋回
		LEFT_TURN,  // 左旋回
	};
public:
	// コンストラクタ
	KeyOperation();
	// デストラクタ
	~KeyOperation();
	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw();
private:
	// キーボード
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

private:
	System::DrawData m_arrowKey[4];	// 十字キー
	System::DrawData m_dashKey;		// 走るキー
	System::DrawData m_shotKey;		// 玉を投げるキー
private:
	const wchar_t* pFileNameKeyUI[4]; // 4方向分
	
};