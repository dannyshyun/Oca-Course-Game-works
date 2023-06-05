#pragma once

#include "Vector2.h"
#include "Vector3.h"

//---------------------------------------------------------------------------------
//	カメラクラス
//---------------------------------------------------------------------------------
class Camera
{
public:
	//	カメラ座標
	Vector3		m_pos;
	//	見る座標
	Vector3		m_look;
	Vector3		m_rot;

	void Init();		//	初期化処理
	void Update();		//	更新処理
	void Render();		//	描画処理
	void Exit();		//	終了処理
};
