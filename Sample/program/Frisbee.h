#pragma once
#include <vector>
#include "Base.h"
#include "Coin.h"

class Frisbee : public Base
{
public:
	void Init(int model);													   //	初期化処理
	void Update(Vector3 player_pos, Vector3 player_rot, Vector3 hit_coin_pos); //	更新処理
	void Render();															   //	描画処理
	void Exit();															   //	終了処理

	bool CheckCoinHit(Coin *coin);
	bool CheckCatch(Vector3 player_pos, float player_radius);

private:
	void Loop(Vector3 coin_pos);
	Vector3 m_move;
	int time_count;
	int hit_count;
	void posInit(Vector3 player_pos, Vector3 player_rot);
	bool isMove = false;
	bool isLoop = false;
	bool isCatchable = false;
};
