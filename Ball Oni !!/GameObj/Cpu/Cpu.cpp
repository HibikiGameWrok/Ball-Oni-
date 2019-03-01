//
//	File	 : Cpu.cpp
//
//  Contents : �錾���ꂽCpu�N���X�̃����o�[�֐��ƃ����o�[�ϐ��̒�`
//
//	name	 : Hibiki Yoshiyasu
//
#include "../../pch.h"
#include "../../Control/Keyboard_Control.h"
#include "Cpu.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace System;

#pragma region Constructor
/// <summary>
/// �R���X�g���N�^
/// </summary>
Cpu::Cpu(DirectX::SimpleMath::Vector3 pos, float dir)
	:m_moveFlag(STOP) // �����o�[�ϐ��̏�����
	,m_frameTime_Ai(0)
	,m_secondsTime_Ai(0)
	,m_randAction(0)
	,m_stanTime(STAN_MAXTIME)
	,m_stanFlag(false)
	,m_shotFlag(false)
{
	m_pos = pos;
	m_dir = XMConvertToRadians(dir);
}
#pragma endregion 

#pragma region Start
/// <summary>
/// ����������
/// </summary>
void Cpu::Start()
{
	// �t�@�C���p�X
	System::Draw3DManager::GetInstance().SetFilePath(m_modelFile, L"Resources\\Models", L"Resources\\Models\\CP.cmo");
	
	// ���������Ɗp�x��ݒ�
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_dir);
	
	// �����T�C�Y��ݒ�
	m_scale = Vector3(10.0f, 10.0f, 10.0f);
	
	// ���[���h���W���X�V
	m_world = Matrix::CreateScale(m_scale) *  Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);

	System::Draw3DManager::GetInstance().SetWorld(m_world);

	// �����蔻��J�v�Z���^�̐ݒ�
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
/// <param name="elapsedTime">�X�V����</param>
/// <returns>�X�V�t���O</returns>
bool Cpu::Update(float elapsedTime)
{
	m_vel = Vector3::Zero;
	static int timer = 0;
	if (m_stanFlag == false)
	{
		timer++;
		// �Ώە��֊p�x���擾
		m_dir = TargetAngle(m_pos.x, m_pos.z, m_targetPos.x, m_targetPos.z);

		// �S�̎��͒ǂ�������
		if (m_oniFlag == true)
		{
			m_vel.x = MOVE_SPEED / 2 * sin(m_dir);
			m_vel.z = MOVE_SPEED / 2 * cos(m_dir);

			// �ʂ�łm�����擾
			int shotRandom = 0;
			if (timer > 120)
			{
				shotRandom = rand() % 6 + 1;
				timer = 0;
			}
			if (m_shotFlag == false)
			{
				// shotRandom��1�̎��ł�
				m_shotFlag = shotRandom == 1 ? true : false;
			}
		}

		// �S����Ȃ����͓�����
		if (m_oniFlag == false)
		{
			m_vel.x = MOVE_SPEED / 2 * sin(-m_dir);
			m_vel.z = MOVE_SPEED / 2 * cos(-m_dir);
		}


		/*Ai_Move();*/

		//switch (m_moveFlag)
		//{
		//case FORWARD:	// �O�i
		//	m_vel.z = MOVE_SPEED;
		//	break;
		//case BACK:		// ���
		//	m_vel.z = MOVE_SPEED * static_cast<float>(-0.5f);
		//	break;
		//case RIGHT_TURN:// �E����
		//	// �v���C���[�̊p�x������
		//	m_dir -= XMConvertToRadians(45.0f);
		//	break;
		//case LEFT_TURN: // ������
		//	m_dir += XMConvertToRadians(45.0f);
		//	break;
		//default:
		//	break;
		//}
	}
	
	Hit_DownMotion();
	
	// �v���C���[���ړ�������
	// �w�肵���l�����ɉ�]
	Vector3 trans;
	m_rot = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f),m_dir + XMConvertToRadians(180));

	// ������ς���
	//trans = Vector3::Transform(m_vel, m_rot);

	// ���W�Ɍ����Ƒ��x��^����
	m_pos -= m_vel;

	// �ړ��t���O�����Z�b�g
	/*m_moveFlag = STOP;*/

	// ���[���h�s��̍쐬
	// ��]���Ă���ړ�
	m_world = Matrix::CreateScale(m_scale) * Matrix::CreateFromQuaternion(m_rot) * Matrix::CreateTranslation(m_pos);
	//System::Draw3DManager::GetInstance().SetWorld(m_world);
	return true;
}
#pragma endregion 

#pragma region Draw
/// <summary>
/// �`�揈���֐�
/// </summary>
void Cpu::Draw()
{
	// �`��
	System::Draw3DManager::GetInstance().Draw(m_modelFile,m_world);
}
#pragma endregion 

#pragma region Ai_Move
/// <summary>
/// �ȈՓI�^�C�}�[���s���֐�
/// </summary>
void Cpu::Ai_Move()
{
	// �j���[�����l�b�g���[�N�I�u�W�F�N�g�𐶐�����
	m_pTheBrain = new NeuralNetwork();

	// �j���[�����l�b�g���[�N������������
	m_pTheBrain->Initialize(2, 5, 3);

	// �w�K����ݒ肷��
	m_pTheBrain->SetLearningRate(0.3);

	// �������g��ݒ肷��
	m_pTheBrain->SetMomentum(true, 0.8);

	double	error = 1.0;
	int		count = 0;

	while (error > 0.01 && count < 10000) {
		error = 0.0;
		count++;
		for (int i = 0; i<MAX_NUM_DATA; i++) {
			m_pTheBrain->SetInput(0, TrainingSet[i][0]);			// ����
			m_pTheBrain->SetInput(1, TrainingSet[i][1]);			// �S���ǂ���
			
			m_pTheBrain->SetDesiredOutput(0, TrainingSet[i][2]);	// ������
			m_pTheBrain->SetDesiredOutput(1, TrainingSet[i][3]);	// �ǂ�������
			m_pTheBrain->SetDesiredOutput(2, TrainingSet[i][4]);	// ����

			m_pTheBrain->FeedForward();								// �O���`�d����(Feed forward)
			error += m_pTheBrain->CalculateError();					// �덷���v�Z����(Calculate error)
			m_pTheBrain->BackPropagate();							// �덷�t�`�d����(Back propagate)
		}
		error = error / MAX_NUM_DATA;
	}

	// ���̓f�[�^���Z�b�g����
	m_pTheBrain->SetInput(0, 1.0); // ����
	m_pTheBrain->SetInput(1, 0.7); // �S���ǂ���

	// �j���[�����l�b�g���[�N�ɏo�̓f�[�^��₢���킹��
	m_pTheBrain->FeedForward();

	// �o�͂��擾
	m_pTheBrain->GetOutput(0);
	m_pTheBrain->GetOutput(1);
	m_pTheBrain->GetOutput(2);

	// ��ԍ����l�̏o��ID���擾
	int outputId = m_pTheBrain->GetMaxOutputID();

	// �l�������o�͂ɂ���čs��������
	switch (outputId)
	{
	case 0: // ������
		
		break;
	case 1: // �ǂ�������
		
		break;
	case 2: // ����

		break;
	
	default:
		break;
	}

}
#pragma endregion 

#pragma region Hit_DownMotion
/// <summary>
/// �_�E�����郂�[�V�����֐�
/// </summary>
void Cpu::Hit_DownMotion()
{
	if (m_stanFlag == true)
	{
		m_stanTime -= 1;
		m_dir += XMConvertToRadians(10.0f);

		if (m_stanTime < 0)
		{
			m_stanFlag = false;
			m_stanTime = STAN_MAXTIME;
		}
	}
}
#pragma endregion 

#pragma region Move
/// <summary>
/// �ړ�����
/// </summary>
/// <param name="move">MOVE�񋓑�</param>
void Cpu::Move(MOVE move)
{
	m_moveFlag = move;	// �w�肳�ꂽ�񋓑̓��̈ړ����Ă�
}
#pragma endregion 


/// <summary>
/// �Ώە��ւ̊p�x�����߂�֐�
/// </summary>
/// <returns>�Ώە��ւ�Y������Ƃ����p�x</returns>
float Cpu::TargetAngle(float xMPos, float zMPos, float xTPos, float zTPos)
{
	// �Ώە��Ƃ̍�����ۊ�
	float dPosX;
	float dPosZ;
	// ���߂��p�x��ۊ�
	float angle;

	// �Ώە��Ƃ̍������v�Z
	dPosX = xMPos - xTPos;
	dPosZ = zMPos - zTPos;

	// �����ɂ���Ċp�x�����߂�
	angle = atan2(dPosX, dPosZ);

	return angle;
}
