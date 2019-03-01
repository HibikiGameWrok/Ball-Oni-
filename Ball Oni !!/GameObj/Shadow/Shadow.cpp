//
//	File	 : Shadow.cpp
//
//  Contents : Shadowクラスの定義
//
//	name	 : Hibiki Yoshiyasu
//
#include "../../pch.h"
#include "Shadow.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Shadow::Shadow()
{
}

Shadow::Shadow(DirectX::SimpleMath::Vector3 pos)
{

}

Shadow::~Shadow()
{
}

void Shadow::Start()
{
	// ファイルパスを設定
	System::Draw3DManager::GetInstance().SetFilePath(m_modelFile, L"Resources\\Models", L"Resources\\Models\\Shadow.cmo");
}

bool Shadow::Update(float elapsedTime)
{
	// 初期サイズを設定
	m_scale = Vector3(0.3f, 0.3f, 0.3f);
	// ワールド座標を設定
	m_world = Matrix::CreateScale(m_scale) * Matrix::CreateTranslation(m_pos);
	return true;
}

void Shadow::Draw()
{
	// コモンステート
	DirectX::CommonStates* states = DX::DeviceResources::GetInstance().GetCommonStates();
	ID3D11DeviceContext* context = DX::DeviceResources::GetInstance().GetD3DDeviceContext();

	// 影のラムダ式
	auto SetCustomShadowState = [&]()
	{
		// 半透明をオン(OM[Get]BlendStateと間違えやすい)
		//  ::必ずモデルの時はAlphaBlend()「除算済みアルファ」を使う
		context->OMSetBlendState(states->AlphaBlend(), nullptr, 0xFFFFFFFF);
		// 深度バッファを使用せず必ず描画する設定
		context->OMSetDepthStencilState(states->DepthNone(), 0);
	};

	// 描画
	System::Draw3DManager::GetInstance().Draw(m_modelFile, m_world,SetCustomShadowState);
}
