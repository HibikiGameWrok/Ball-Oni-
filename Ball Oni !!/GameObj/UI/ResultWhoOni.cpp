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
	// プレイヤーが勝った時に描画する画像
	// ファイルパスをロード
	System::DrawManager::GetInstance().LoadTexture(m_imagePlayerWin, m_pFileName_Player);
	// 画像の範囲
	m_imagePlayerWin.SetRect(212, 30);
	// 画像の中心
	m_imagePlayerWin.SetOrigin(212 / 2, 30 / 2);
	// 画像の大きさ
	m_imagePlayerWin.SetScale(2,2);
	// 画像の座標
	m_imagePlayerWin.SetPos(800 / 2, 300);

	// 敵(CPU)が勝った時に描画する画像
	// ファイルパスをロード
	System::DrawManager::GetInstance().LoadTexture(m_imageCPUWin, m_pFileName_cpu);
	// 画像の範囲
	m_imageCPUWin.SetRect(212, 30);
	// 画像の中心
	m_imageCPUWin.SetOrigin(212 / 2, 30 / 2);
	// 画像の大きさ
	m_imageCPUWin.SetScale(2, 2);
	// 画像の座標
	m_imageCPUWin.SetPos(800 / 2, 300);
}

bool ResultWhoOni::Update(float elapsedTime)
{
	return true;
}


void ResultWhoOni::Draw()
{
	// 描画
	if ((m_whoOni != 1)&&(m_whoOni != 0))
	{
		System::DrawManager::GetInstance().Draw(m_imagePlayerWin);
	}
	else if ((m_whoOni == 1) && (m_whoOni != 0))
	{
		System::DrawManager::GetInstance().Draw(m_imageCPUWin);
	}
}
