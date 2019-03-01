//
//	File	 : JudgeUI.cpp
//
//  Contents : �N���S�Ȃ̂���m�点��UI��`�悷��
//
//	name	 : Hibiki Yoshiyasu
//
#include "JudgeUI.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
JudgeUI::JudgeUI()
	:mp_FileNamePlayer(L"Resources\\Textures\\PlayScene\\JudgePlayer.png")
	, mp_FileNameCpu(L"Resources\\Textures\\PlayScene\\JudgeCpu.png")
	, m_numChara(0)
	, m_moveUIFlag(false)
	, m_uiScale{1, 1}
	, m_framesTime(0)
	, m_secondsTime(0)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
JudgeUI::~JudgeUI()
{
}

/// <summary>
/// ������
/// </summary>
void JudgeUI::Start()
{
	System::DrawManager::GetInstance().LoadTexture(m_judgePlayer, mp_FileNamePlayer);
	m_judgePlayer.SetRect(230,30);
	m_judgePlayer.SetPos(800, 0);
	m_judgePlayer.SetOrigin(230, 0);
	m_judgePlayer.SetScale(m_uiScale[0], m_uiScale[0]);

	System::DrawManager::GetInstance().LoadTexture(m_judgeCpu, mp_FileNameCpu);
	m_judgeCpu.SetRect(230, 30);
	m_judgeCpu.SetPos(800, 0);
	m_judgeCpu.SetOrigin(230, 0);
	m_judgeCpu.SetScale(m_uiScale[1], m_uiScale[1]);
}

/// <summary>
/// �X�V
/// </summary>
/// <returns>�I�����</returns>
bool JudgeUI::Update(float elapsedTime)
{
	GetNowOni();

	//if (m_numChara != 1)
	//{
	//	m_uiScale[0] = 5;
	//}
	//else
	//if (m_numChara != 2)
	//{
	//	m_uiScale[1] = 5;
	//}

	//if (m_moveUIFlag == true)
	//{
	//	if (m_framesTime < 60)
	//	{
	//		m_framesTime += 1;
	//	}
	//	else
	//		if (m_framesTime == 60)
	//		{
	//			m_secondsTime += 1;
	//			m_framesTime = 0;
	//		}

	//	//if (m_numChara == 1)
	//	//{

	//	//}
	//	//else
	//	if (m_numChara == 2)
	//	{
	//		if (m_uiScale[1] > 1)
	//		{
	//			if (m_secondsTime < 3) {
	//		    	m_uiScale[1] -= 0.1f;
	//				m_secondsTime = 0;
	//			}
	//		}
	//	}
	//}

	//m_uiScale[0] = 1;
	//m_uiScale[1] = 1;
	//m_judgePlayer.SetScale(m_uiScale[0], m_uiScale[0]);
	//m_judgeCpu.SetScale(m_uiScale[1], m_uiScale[1]);
	return true;
}


/// <summary>
/// �`��
/// </summary>
void JudgeUI::Draw()
{
	if (m_numChara == 1)
	{
		System::DrawManager::GetInstance().Draw(m_judgePlayer);
	}

	if (m_numChara == 2)
	{
		System::DrawManager::GetInstance().Draw(m_judgeCpu);
	}
}

/// <summary>
/// �N���S���ݒ肷��֐�
/// </summary>
void JudgeUI::SetNowOni(unsigned __int8 num)
{
	m_numChara = num;
}

/// <summary>
/// �N���S�����K������֐�
/// </summary>
unsigned __int8 JudgeUI::GetNowOni()
{
	return m_numChara;
}


