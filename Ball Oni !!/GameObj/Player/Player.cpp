//
//	File	 : Player.cpp
//
//  Contents : Player�N���X�̊֐��ƕϐ��̒�`
//
//	name	 : Hibiki Yoshiyasu
//
#include "../../pch.h"
#include "../../Control/keyboard_control.h"
#include "Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace System;

#pragma region Constructor
/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player(DirectX::SimpleMath::Vector3 pos,float dir)
	: m_moveFlag(STOP),m_dashFlag(false), m_oniFlag(false), m_stopFlag(true) // �����o�[�ϐ��̏�����
{
	m_pos = pos;
	m_dir = XMConvertToRadians(dir);
}
#pragma endregion

#pragma region Update
/// <summary>
/// ����������
/// </summary>
void Player::Start()
{
	Draw3DManager::GetInstance().SetFilePath(m_modelFile, L"Resources\\Models", L"Resources\\Models\\PL.cmo");

	// ���������Ɗp�x��ݒ�
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_dir);

	// �����T�C�Y��ݒ�
	m_scale = Vector3(10.0f, 10.0f, 10.0f);

	// ���[���h���W���v�Z
	m_world = Matrix::CreateScale(m_scale) * Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);
	Draw3DManager::GetInstance().SetWorld(m_world);

	// �����蔻�苅�^�̐ݒ�
	Collision::Sphere sphere;
	sphere.c = Vector3(0, 0, 0);
	sphere.r = 0.3f;
	this->SetCollision(sphere);
}
#pragma endregion

#pragma region Update
/// <summary>
/// �X�V����
/// </summary>
bool Player::Update(float elapsedTime)
{ 
	if (m_stopFlag == false)
	{
		// �R���g���[���X�V
		Key_Control::GetInstance().Update();
		__int8 action = Key_Control::GetInstance().GetActionVal();
		// �x���Ȃ�t���O�Ɏ擾
		m_srowFlag = Key_Control::GetInstance().GetDashFlag();
		// ���˃t���O���擾
		m_shotFlag = Key_Control::GetInstance().GetShotFlag();

		// ���x�����Z�b�g����
		m_vel = Vector3::Zero;

		// �񋓑̂̃p�^�[��
		switch (action)
		{
		case FORWARD:	    // �O�i
			if (m_dashFlag) {
				m_vel.z = DASH_SPEED;
			}
			else {
				m_vel.z = MOVE_SPEED;
			}
			break;
		case BACK:		    // ���
			if (m_dashFlag) {
				m_vel.z = DASH_SPEED * static_cast<float>(-0.5f);
			}
			else {
				m_vel.z = MOVE_SPEED * static_cast<float>(-0.5f);
			}
			break;
		case LEFT_TURN:    // �E�ړ�
			m_dir += XMConvertToRadians(2.0f);
			break;
		case RIGHT_TURN:     // ���ړ�
			m_dir -= XMConvertToRadians(2.0f);
			break;
		case RIGHT_FOR:	// �E����
			if (m_dashFlag)
			{
				m_dir -= XMConvertToRadians(2.0f);
				m_vel.x = DASH_SPEED * static_cast<float>(-0.3f);
				m_vel.z = DASH_SPEED;
			}
			else
			{
				m_dir -= XMConvertToRadians(2.0f);
				m_vel.x = MOVE_SPEED * static_cast<float>(-0.5f);
				m_vel.z = MOVE_SPEED;
			}
			break;
		case RIGHT_BACK:  // �E�΂ߌ��
			if (m_dashFlag)
			{
				m_vel.x = DASH_SPEED * static_cast<float>(-0.5f);
				m_vel.z = DASH_SPEED * static_cast<float>(-0.5f);
			}
			else
			{
				m_vel.x = MOVE_SPEED * static_cast<float>(-0.5f);
				m_vel.z = MOVE_SPEED * static_cast<float>(-0.5f);
			}
			break;
		case LEFT_FOR:	// ������
			if (m_dashFlag)
			{
				m_dir += XMConvertToRadians(2.0f);
				m_vel.x = DASH_SPEED * static_cast<float>(0.3f);
				m_vel.z = DASH_SPEED;
			}
			else
			{
				m_dir += XMConvertToRadians(2.0f);
				m_vel.x = MOVE_SPEED * static_cast<float>(0.5f);
				m_vel.z = MOVE_SPEED;
			}
			break;
		case LEFT_BACK:	// ���΂ߌ��ړ�
			if (m_dashFlag)
			{
				m_vel.x = DASH_SPEED * static_cast<float>(0.5f);
				m_vel.z = DASH_SPEED * static_cast<float>(-0.5f);
			}
			else
			{
				m_vel.x = MOVE_SPEED * static_cast<float>(0.5f);
				m_vel.z = MOVE_SPEED * static_cast<float>(-0.5f);
			}
			break;
		default:
			break;
		}
		Key_Control::GetInstance().SetAction(Key_Control::NONE);

		// �v���C���[���ړ�������
		// �w�肵���l�����ɉ�]
		Vector3 trans;
		m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_dir);

		// ���W�֑��x�ƌ�������
		trans = Vector3::Transform(m_vel, m_rot);
		m_pos += trans;

		// ���[���h�s��̍쐬
		// ��]���Ă���ړ�
		m_world = Matrix::CreateScale(m_scale) * Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);

		System::Draw3DManager::GetInstance().SetWorld(m_world);
	}
	return true; 
}

#pragma endregion

#pragma region Draw
/// <summary>
/// �`�揈��
/// </summary>
void Player::Draw()
{
	// �`��
	System::Draw3DManager::GetInstance().Draw(m_modelFile, m_world);
}
#pragma endregion

