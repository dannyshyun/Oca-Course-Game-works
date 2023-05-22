#pragma once
#include "Base.h"

class Frisbee : Base
{
public:

	void Init(int model, Vector3 player_pos, Vector3 player_rot);		//	初期化処理
	void Update();		//	更新処理
	void Render();		//	描画処理
	void Exit();		//	終了処理
	
private:
	Vector3 m_move;
};
