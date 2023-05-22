#pragma once
#include "Base.h"

class Frisbee : Base
{
public:

	void Init(int model, Vector3 player_pos, Vector3 player_rot);		//	����������
	void Update();		//	�X�V����
	void Render();		//	�`�揈��
	void Exit();		//	�I������
	
private:
	Vector3 m_move;
};
