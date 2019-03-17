#include "StartSign.h"

/// <summary>
/// コンストラクタ
/// </summary>
StartSignUI::StartSignUI()
{
}

/// <summary>
/// デストラクタ
/// </summary>
StartSignUI::~StartSignUI()
{
}

/// <summary>
/// 開始処理
/// </summary>
void StartSignUI::Start()
{
	System::DrawManager::GetInstance().LoadTexture(m_imageStartSignUI, L"Resources\\Textures\\PlayScene\\StartSign.png");
	m_imageStartSignUI.SetRect(550, 150);
	m_imageStartSignUI.SetOrigin(550 / 2, 150 / 2);
	m_imageStartSignUI.SetPos(800 / 2, 600 / 2);
}

/// <summary>
/// 更新処理
/// </summary>
bool StartSignUI::Update(float elapsedTime)
{
	return true;
}

/// <summary>
/// 描画処理
/// </summary>
void StartSignUI::Draw()
{
	System::DrawManager::GetInstance().Draw(m_imageStartSignUI);
}
