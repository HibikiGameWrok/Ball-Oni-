#include "PleaseSpaceUI.h"

PleaseSpaceUI::PleaseSpaceUI(DirectX::SimpleMath::Vector2 pos)
	:m_frameTime(0)
	,m_flashingImage(true)
	, m_pos(pos)
{
}

PleaseSpaceUI::~PleaseSpaceUI()
{
}

void PleaseSpaceUI::Start()
{
	System::DrawManager::GetInstance().LoadTexture(m_imagePleaseSpaceUI, L"Resources\\Textures\\TitleScene\\PleaseSpace.png");
	m_imagePleaseSpaceUI.SetRect(450, 80);
	m_imagePleaseSpaceUI.SetOrigin(450 / 2, 80 / 2);
	m_imagePleaseSpaceUI.SetPos(m_pos.x, m_pos.y);
}

bool PleaseSpaceUI::Update(float elapsedTime)
{
	Change();
	return true;
}

void PleaseSpaceUI::Draw()
{
	if (m_flashingImage == true)
	{
		System::DrawManager::GetInstance().Draw(m_imagePleaseSpaceUI);
	}
}

void PleaseSpaceUI::Change()
{
	m_frameTime++;
	if (m_frameTime > 20)
	{
		if (m_flashingImage == true)
		{
			m_flashingImage = false;
		}
		else
		{
			m_flashingImage = true;
		}	
		m_frameTime = 0;
	}
}
