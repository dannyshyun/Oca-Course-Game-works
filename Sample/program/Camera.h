#pragma once

#include "Vector3.h"

//---------------------------------------------------------------------------------
//	カメラクラス
//---------------------------------------------------------------------------------
class Camera
{
public:
	Vector3 m_pos;
	Vector3 m_look;

	void Init();										 //	初期化処理
	void Update(const Vector3 &pos, const Vector3 &rot); //	更新処理
	void Render();										 //	描画処理
	void Exit();										 //	終了処理
};
