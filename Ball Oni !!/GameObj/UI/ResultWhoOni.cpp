#include "../../pch.h"
#include "ResultWhoOni.h"

ResultWhoOni::ResultWhoOni(unsigned __int8 whoOni = 0)
	:m_whoOni(whoOni)
	,m_pFileName_Player(L"Resources\\Textures\\ResultScene\\OniResult_playerWin.png")
	, m_pFileName_cpu(L"Resources\\Textures\\ResultScene\\OniResult_EnemeyWin.png")
{
}

ResultWhoOni::~ResultWhoOni()
{
}

void ResultWhoOni::Start()
{
	// �v���C���[�����������ɕ`�悷��摜
	// �t�@�C���p�X�����[�h
	System::DrawManager::GetInstance().LoadTexture(m_imagePlayerWin, m_pFileName_Player);
	// �摜�͈̔�
	m_imagePlayerWin.SetRect(212, 30);
	// �摜�̒��S
	m_imagePlayerWin.SetOrigin(212 / 2, 30 / 2);
	// �摜�̑傫��
	m_imagePlayerWin.SetScale(2,2);
	// �摜�̍��W
	m_imagePlayerWin.SetPos(800 / 2, 300);

	// �G(CPU)�����������ɕ`�悷��摜
	// �t�@�C���p�X�����[�h
	System::DrawManager::GetInstance().LoadTexture(m_imageCPUWin, m_pFileName_cpu);
	// �摜�͈̔�
	m_imageCPUWin.SetRect(212, 30);
	// �摜�̒��S
	m_imageCPUWin.SetOrigin(212 / 2, 30 / 2);
	// �摜�̑傫��
	m_imageCPUWin.SetScale(2, 2);
	// �摜�̍��W
	m_imageCPUWin.SetPos(800 / 2, 300);
}

bool ResultWhoOni::Update(float elapsedTime)
{
	return true;
}


void ResultWhoOni::Draw()
{
	// �`��
	if ((m_whoOni != 1)&&(m_whoOni != 0))
	{
		System::DrawManager::GetInstance().Draw(m_imagePlayerWin);
	}
	else if ((m_whoOni == 1) && (m_whoOni != 0))
	{
		System::DrawManager::GetInstance().Draw(m_imageCPUWin);
	}
}
