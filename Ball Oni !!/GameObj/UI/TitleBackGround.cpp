#include "TitleBackGround.h"

TitleBackGround::TitleBackGround()
{
}

TitleBackGround::~TitleBackGround()
{
}

void TitleBackGround::Start()
{
	System::DrawManager::GetInstance().LoadTexture(m_imageBackGround, L"Resources\\Textures\\TitleScene\\Title.png");
	m_imageBackGround.SetRect(800,600);
	m_imageBackGround.SetPos(0, 0);
}

bool TitleBackGround::Update()
{
	return true;
}

//bool TitleBackGround::Update(DX::StepTimer timer)
//{
//	return true;
//}

void TitleBackGround::Draw()
{
	System::DrawManager::GetInstance().Draw(m_imageBackGround);
}
