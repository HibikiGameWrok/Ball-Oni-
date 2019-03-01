#pragma once

#include "../../TaskSystem/TaskBase.h"
#include "../../Manager/DrawManager.h"

class ResultWhoOni : public Task::TaskBase
{
public:
	// コンストラクタ
	ResultWhoOni() {};
	ResultWhoOni(unsigned __int8 whoOni);
	// デストラクタ
	~ResultWhoOni();

	// 初期化
	void Start();
	// 更新処理
	bool Update(float elapsedTime);
	// 描画
	void Draw();

private:
	unsigned __int8 m_whoOni;

	System::DrawData m_imagePlayerWin;
	System::DrawData m_imageCPUWin;
	const wchar_t* m_pFileName_Player;
	const wchar_t* m_pFileName_cpu;
};
