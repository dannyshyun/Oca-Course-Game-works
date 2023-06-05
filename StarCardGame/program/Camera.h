#pragma once

#include "Vector2.h"
#include "Vector3.h"

//---------------------------------------------------------------------------------
//	�J�����N���X
//---------------------------------------------------------------------------------
class Camera
{
public:
	//	�J�������W
	Vector3		m_pos;
	//	������W
	Vector3		m_look;
	Vector3		m_rot;

	void Init();		//	����������
	void Update();		//	�X�V����
	void Render();		//	�`�揈��
	void Exit();		//	�I������
};
