#include <vector>
#include "Main.h"
#include "Game.h"
#include "Hit.h"
#include "Base.h"
#include "Camera.h"
#include "Ground.h"
#include "Player.h"
#include "Npc.h"
#include "Coin.h"
#include "Frisbee.h"

//	各モデルデータ用の変数
int ground_model;
int player_model;
int npc_model;
int coin_model;
int frisbee_model;

Camera camera;
Ground ground;
Player player;
Npc npc;
std::vector<Coin *> coins;
Frisbee frisbee;

//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void GameInit()
{
	//	各モデルデータの読み込み
	ground_model = MV1LoadModel("data/ground.mqoz");
	// player_model = MV1LoadModel("SampleData/Model/player00.mv1");
	// player_model = MV1LoadModel( "data/player.mqoz" );
	npc_model = MV1LoadModel("SampleData/Model/10505_Frisbee_v3_L3.mv1");
	coin_model = MV1LoadModel("SampleData/Model/coin.mv1");
	frisbee_model = MV1LoadModel("SampleData/Model/10505_Frisbee_v3_L3.mv1");

	SetMouseDispFlag(FALSE);
	SetMousePoint(SCREEN_W / 2, SCREEN_H / 2);
	camera.Init();
	ground.Init(ground_model);
	player.Init(player_model);
	npc.Init(npc_model);
	coins =
		{
			new Coin(coin_model, Vector3(3.f, 4.5f, 2.f)),
			new Coin(coin_model, Vector3(-3.f, 4.5f, 2.f)),
			new Coin(coin_model, Vector3(3.f, 4.5f, -2.f))};
	frisbee.Init(frisbee_model);
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
	ground.Update();
	player.Update();
	npc.Update();
	for (auto &coin : coins)
	{
		if (coin)
		{
			coin->Update();
			if (CheckBallHit(frisbee.m_pos, frisbee.m_radius, coin->m_pos, coin->m_radius))
			{
				delete coin;
				coin = nullptr;
			}
		}
	}
	frisbee.Update(player.m_pos, player.m_rot);

	camera.Update(player.m_pos, player.m_rot);
	SetMousePoint(SCREEN_W / 2, SCREEN_H / 2);
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void GameRender()
{
	camera.Render();

	ground.Render();
	npc.Render();
	for (auto &coin : coins)
		if (coin)
			coin->Render();
	player.Render();
	frisbee.Render();

	SetMouseDispFlag(FALSE);
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void GameExit()
{
	camera.Exit();
	ground.Exit();
	player.Exit();
	npc.Exit();
	for (auto &coin : coins)
		if (coin)
		{
			coin->Exit();
			delete coin;
		}

	MV1DeleteModel(ground_model);
	MV1DeleteModel(player_model);
	MV1DeleteModel(npc_model);
	MV1DeleteModel(coin_model);
}
