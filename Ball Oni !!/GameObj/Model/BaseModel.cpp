#include "../../pch.h"
#include "BaseModel.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

#pragma region Constructor
/// <summary>
/// コンストラクタ
/// </summary>
ModelObject::ModelObject()
	:m_direction(NULL)
	,m_scale(1)
	,m_pos(Vector3::Zero)
	,m_rotation(Quaternion::Identity)
{
}
#pragma endregion

#pragma region Destructor
/// <summary>
/// デストラクタ
/// </summary>
ModelObject::~ModelObject()
{
}
#pragma endregion

#pragma region Create
/// <summary>
/// 継承したクラスの描画
/// </summary>
/// <param name="deviceResources">デバイスリソース</param>
/// /// <param name="fxFile">マテリアルのファイルパス</param>
/// <param name="cmoFile">CMOのファイルパス</param>
void ModelObject::Create(DX::DeviceResources* deviceResources,const wchar_t * effectFile,const wchar_t * cmoFile)
{
	// デバイスは一回しか使わないのでローカル変数
	ID3D11Device* device = deviceResources->GetD3DDevice();
	// コンテキストは作成後の描画で使うのでグローバル変数
	m_context = deviceResources->GetD3DDeviceContext();

	// マテリアルのファイルパスを登録
	EffectFactory effect(device);
	effect.SetDirectory(effectFile);

	// モデルの作成
	m_modelFile = Model::CreateFromCMO(device, cmoFile, effect);
	m_model = m_modelFile.get();
}
#pragma endregion

#pragma region Render
//void ModelObject::Render(DirectX::CommonStates * states,DirectX::SimpleMath::Matrix view,DirectX::SimpleMath::Matrix projection)
//{
//	/*m_world = Matrix::CreateTranslation(m_pos);*/
//
//		// モデルを描画
//	m_model->Draw(
//		m_context,
//		*states,
//		m_world,
//		view,
//		projection,
//		false
//	);
//}
#pragma endregion