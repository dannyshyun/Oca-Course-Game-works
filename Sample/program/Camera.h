#pragma once

#include "Vector3.h"

//---------------------------------------------------------------------------------
//	�J�����N���X
//---------------------------------------------------------------------------------
class Camera
{
public:
	Vector3 m_pos;
	Vector3 m_look;

	void Init();										 //	����������
	void Update(const Vector3 &pos, const Vector3 &rot); //	�X�V����
	void Render();										 //	�`�揈��
	void Exit();										 //	�I������
};
