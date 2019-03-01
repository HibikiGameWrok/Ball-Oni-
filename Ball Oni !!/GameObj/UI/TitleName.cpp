#include "TitleName.h"

TitleName::TitleName()
{
}

TitleName::~TitleName()
{
}

void TitleName::Start()
{
	System::DrawManager::GetInstance().LoadTexture(m_imageTitel, L"Resources\\Textures\\TitleScene\\TitleName.png");
	m_imageTitel.SetRect(350, 80);
	m_imageTitel.SetOrigin(350 / 2, 80 / 2);
	m_imageTitel.SetPos(400, 150);
}

bool TitleName::Update(float elapsedTime)
{
	return true;
}

void TitleName::Draw()
{
	System::DrawManager::GetInstance().Draw(m_imageTitel);
}
