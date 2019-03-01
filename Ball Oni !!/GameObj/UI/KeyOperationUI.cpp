#include "KeyOperationUI.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

KeyOperation::KeyOperation()
{
	// 十字キーのUI画像を4方向分ファイルパスを登録
	pFileNameKeyUI[0] = L"Resources\\Textures\\key\\Up.png";
	pFileNameKeyUI[1] = L"Resources\\Textures\\key\\Down.png";
	pFileNameKeyUI[2] = L"Resources\\Textures\\key\\Left.png";
	pFileNameKeyUI[3] = L"Resources\\Textures\\key\\Right.png";
}

KeyOperation::~KeyOperation()
{

}

void KeyOperation::Start()
{
#pragma region 十字キー
	for (int i = 0; i < 4; i++)
	{
		System::DrawManager::GetInstance().LoadTexture(m_arrowKey[i], pFileNameKeyUI[i]);
		m_arrowKey[i].SetRect(46, 46);
	}
	m_arrowKey[0].SetPos(600, 400);	// 上
	m_arrowKey[1].SetPos(600, 500); // 下
	m_arrowKey[2].SetPos(550, 450); // 左
	m_arrowKey[3].SetPos(650, 450); // 右
#pragma endregion

#pragma region ダッシュ移動＆玉を投げる
	System::DrawManager::GetInstance().LoadTexture(m_dashKey, L"Resources\\Textures\\key\\Qkey.png");
	m_dashKey.SetRect(46,46);
	m_dashKey.SetPos(70,450);
	System::DrawManager::GetInstance().LoadTexture(m_shotKey, L"Resources\\Textures\\key\\Ekey.png");
	m_shotKey.SetRect(46, 46);
	m_shotKey.SetPos(180, 450);
#pragma endregion
}

bool KeyOperation::Update(float elapsedTime)
{
	// キー入力
	Keyboard::State kb = Keyboard::Get().GetState();

	if ((kb.Up)||(kb.I))
	{
		m_arrowKey[0].SetRect(46,0,92, 46);
	}
	else
	{
		m_arrowKey[0].SetRect(0,0,46, 46);
	}

	if ((kb.Down)||(kb.K))
	{
		m_arrowKey[1].SetRect(46, 0, 92, 46);
	}
	else
	{
		m_arrowKey[1].SetRect(0, 0, 46, 46);
	}

	if ((kb.Left)||(kb.J))
	{
		m_arrowKey[2].SetRect(46, 0, 92, 46);
	}
	else
	{
		m_arrowKey[2].SetRect(0, 0, 46, 46);
	}

	if ((kb.Right)||(kb.L))
	{
		m_arrowKey[3].SetRect(46, 0, 92, 46);
	}
	else
	{
		m_arrowKey[3].SetRect(0, 0, 46, 46);
	}

	if (kb.Q)
	{
		m_dashKey.SetRect(46, 0, 92, 46);
	}
	else
	{
		m_dashKey.SetRect(0, 0, 46, 46);
	}

	if (kb.E)
	{
		m_shotKey.SetRect(46, 0, 92, 46);
	}
	else
	{
		m_shotKey.SetRect(0, 0, 46, 46);
	}

	return true;
}


void KeyOperation::Draw()
{
	for (int i = 0; i < 4; i++)
	{
		System::DrawManager::GetInstance().Draw(m_arrowKey[i]);
	}
	System::DrawManager::GetInstance().Draw(m_dashKey);
	System::DrawManager::GetInstance().Draw(m_shotKey);
}

