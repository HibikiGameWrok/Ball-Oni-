#include "ResultName.h"

ResultName::ResultName()
	:mp_FileName(L"Resources\\Textures\\ResultScene\\Result.png")
{
}

ResultName::~ResultName()
{
}

void ResultName::Start()
{
	// ファイルパスをロード
	System::DrawManager::GetInstance().LoadTexture(m_image, mp_FileName);
	// 画像の範囲
	m_image.SetRect(250, 80);
	// 画像の中心
	m_image.SetOrigin(250 / 2, 80 / 2);
	// 画像の座標
	m_image.SetPos(800 / 2, 100);
}

bool ResultName::Update(float elapsedTime)
{
	return true;
}

void ResultName::Draw()
{
	// 描画
	System::DrawManager::GetInstance().Draw(m_image);
}
