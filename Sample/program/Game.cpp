#include "Main.h"
#include "Game.h"
#include "Hit.h"

#include "Camera.h"
#include "Ground.h"
#include "Player.h"
#include "Npc.h"

//	各モデルデータ用の変数
int ground_model;
int player_model;
int npc_model;

Camera camera;
Ground ground;
Player player;
Npc npc;

//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void GameInit()
{
	//	各モデルデータの読み込み
	ground_model = MV1LoadModel("data/ground.mqoz");
	player_model = MV1LoadModel("SampleData/Model/player00.mv1");
	// player_model = MV1LoadModel( "data/player.mqoz" );
	npc_model = MV1LoadModel("data/npc.mqoz");

	SetMouseDispFlag(FALSE);
	SetMousePoint(SCREEN_W / 2, SCREEN_H / 2);
	camera.Init();
	ground.Init(ground_model);
	player.Init(player_model);
	npc.Init(npc_model);
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
	ground.Update();
	player.Update();
	npc.Update();

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
	player.Render();
	SetMouseDispFlag(FALSE);
	DrawString(20, 20, "←→キー：プレイヤーの回転", GetColor(255, 255, 255));
	DrawString(20, 40, "↑　キー：向いている方向に移動", GetColor(255, 255, 255));
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

	MV1DeleteModel(ground_model);
	MV1DeleteModel(player_model);
	MV1DeleteModel(npc_model);
}
