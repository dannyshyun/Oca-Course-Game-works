#include "Main.h"
#include "Game.h"
#include "Hit.h"

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
Coin coin;
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
	npc_model = MV1LoadModel("SampleData/Model/coin.mv1");
	coin_model = MV1LoadModel("SampleData/Model/coin.mv1");
	frisbee_model = MV1LoadModel("SampleData/Model/10505_Frisbee_v3_L3.mv1");

	SetMouseDispFlag(FALSE);
	SetMousePoint(SCREEN_W / 2, SCREEN_H / 2);
	camera.Init();
	ground.Init(ground_model);
	player.Init(player_model);
	npc.Init(npc_model);
	coin.Init(coin_model);
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
	ground.Update();
	player.Update();
	npc.Update();
	coin.Update();

	
	if (CheckMouseInput(MOUSE_INPUT_LEFT))
	{
		frisbee.Init(frisbee_model, player.m_pos, player.m_rot);
	}
	frisbee.Update();

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
	coin.Render();
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
	coin.Exit();

	MV1DeleteModel(ground_model);
	MV1DeleteModel(player_model);
	MV1DeleteModel(npc_model);
	MV1DeleteModel(coin_model);
}
