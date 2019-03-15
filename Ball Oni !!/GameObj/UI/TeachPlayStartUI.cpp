#include "TeachPlayStartUI.h"

/// <summary>
/// コンストラクタ
/// </summary>
TeachPlayStartUI::TeachPlayStartUI()
{
}

/// <summary>
/// デストラクタ
/// </summary>
TeachPlayStartUI::~TeachPlayStartUI()
{
}

/// <summary>
/// 開始処理
/// </summary>
void TeachPlayStartUI::Start()
{
	System::DrawManager::GetInstance().LoadTexture(m_imageTeachPlayStartUI, L"Resources\\Textures\\PlayScene\\TeachPlayStart.png");
	m_imageTeachPlayStartUI.SetRect(600, 200);
	m_imageTeachPlayStartUI.SetOrigin(600 / 2, 200 / 2);
	m_imageTeachPlayStartUI.SetPos(800 / 2, 250);
}

/// <summary>
/// 更新処理
/// </summary>
/// <returns>true == 更新, false == 停止 </returns>
bool TeachPlayStartUI::Update(float elapsedTime)
{

	return true;
}

/// <summary>
/// 描画処理
/// </summary>
void TeachPlayStartUI::Draw()
{
	System::DrawManager::GetInstance().Draw(m_imageTeachPlayStartUI);
}

