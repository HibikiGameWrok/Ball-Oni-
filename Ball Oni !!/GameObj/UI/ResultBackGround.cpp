#include "ResultBackGround.h"


ResultBackGround::ResultBackGround()
	:mp_FileName(L"Resources\\Textures\\ResultScene\\ResultBackGround.png")
{
}

ResultBackGround::~ResultBackGround()
{
}

void ResultBackGround::Start()
{
	// ファイルパスをロード
	System::DrawManager::GetInstance().LoadTexture(m_backGound, mp_FileName);
	// 画像の範囲
	m_backGound.SetRect(800, 600);
	// 画像の座標
	m_backGound.SetPos(0,0);
}

bool ResultBackGround::Update(float elapsedTime)
{
	return true;
}

void ResultBackGround::Draw()
{
	// 描画
	System::DrawManager::GetInstance().Draw(m_backGound);
}
