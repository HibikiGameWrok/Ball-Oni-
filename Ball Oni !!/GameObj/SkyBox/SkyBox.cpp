#include "../../pch.h"
#include "SkyBox.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

SkyBox::SkyBox()
{
}

SkyBox::~SkyBox()
{
}

void SkyBox::Start()
{
	// 作成
	System::Draw3DManager::GetInstance().SetFilePath(m_modelFile, L"Resources\\Models", L"Resources\\Models\\rengbox.cmo");

	// 初期座標を設定
	m_pos = Vector3(0.0f, 0.0f, 0.0f);
	// 初期方向と角度
	m_dir = 0.0f;
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_dir);
	// 初期サイズを設定
	m_scale = Vector3(1.0f, 1.0f, 1.0f);

	// ワールド座標
	m_world = m_world = Matrix::CreateScale(m_scale) *  Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);
}

bool SkyBox::Update(float elapsedTime)
{
	return true;
}


void SkyBox::Draw()
{
	// 描画
	System::Draw3DManager::GetInstance().Draw(m_modelFile,m_world);
}
