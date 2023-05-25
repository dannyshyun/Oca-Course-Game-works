#pragma once
#include "Base.h"

class Frisbee : public Base
{
public:

	void Init(int model);		//	����������
	void Update(Vector3 player_pos, Vector3 player_rot);		//	�X�V����
	void Render();		//	�`�揈��
	void Exit();		//	�I������

	bool isMove = false;
	
private:
	Vector3 m_move;
	int time_count;
	void posInit(Vector3 player_pos, Vector3 player_rot);
};
