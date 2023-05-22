#pragma once
#include "Base.h"

class Frisbee : Base
{
public:

	void Init(int model, Vector3 player_pos, Vector3 player_rot);		//	‰Šú‰»ˆ—
	void Update();		//	XVˆ—
	void Render();		//	•`‰æˆ—
	void Exit();		//	I—¹ˆ—
	
private:
	Vector3 m_move;
};
