#include "ImageInstructionKey.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

InstructionKey::InstructionKey()
{
}

InstructionKey::~InstructionKey()
{
}

void InstructionKey::Start()
{
	System::DrawManager::GetInstance().LoadTexture(m_arrowKey, L"Resources\\Textures\\key\\InstructionKey_Move.png");
	m_arrowKey.SetRect(184, 46);
	m_arrowKey.SetScale(0.5f, 0.5f);
	m_arrowKey.SetPos(650, 540);
	System::DrawManager::GetInstance().LoadTexture(m_dashKey, L"Resources\\Textures\\key\\InstructionKey_Q.png");
	m_dashKey.SetRect(184, 46);
	m_dashKey.SetScale(0.5f,0.5f);
	m_dashKey.SetPos(50, 540);
	System::DrawManager::GetInstance().LoadTexture(m_shotKey, L"Resources\\Textures\\key\\InstructionKey_E.png");
	m_shotKey.SetRect(184, 46);
	m_shotKey.SetScale(0.5f, 0.5f);
	m_shotKey.SetPos(180, 540);
}

bool InstructionKey::Update(float elapsedTime)
{
	return true;
}


void InstructionKey::Draw()
{
	System::DrawManager::GetInstance().Draw(m_arrowKey);
	System::DrawManager::GetInstance().Draw(m_dashKey);
	System::DrawManager::GetInstance().Draw(m_shotKey);
}
