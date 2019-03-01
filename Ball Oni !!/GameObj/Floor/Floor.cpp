//
//	File	 : Floor.cpp
//
//  Contents : Floor�N���X�̒�`
//
//	name	 : Hibiki Yoshiyasu
//
#include "../../pch.h"
#include "Floor.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Floor::Floor()
{
}

Floor::~Floor()
{
}

void Floor::Start()
{
	// �t�@�C���p�X��ݒ�
	System::Draw3DManager::GetInstance().SetFilePath(m_modelFile, L"Resources\\Models", L"Resources\\Models\\GreenLawn.cmo");

	// �������W��ݒ�
	m_pos = Vector3(0.0f, 0.0f, 0.0f);

	// ����������ݒ�
	m_dir = 0.0f;
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_dir);

	// �����T�C�Y��ݒ�
	m_scale = Vector3(1.0f, 1.0f, 1.0f);

	// ���[���h���W��ݒ�
	m_world = Matrix::CreateScale(m_scale) * Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);
}


bool Floor::Update(float elapsedTime)
{
	return true;
}


void Floor::Draw()
{
	// �`��
	System::Draw3DManager::GetInstance().Draw(m_modelFile,m_world);
}
