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
#include "UI.h"

#define COIN_NUM 20
#define FRAME_PER_SECOND 60

//	各モデルデータ用の変数
int ground_model;
int player_model;
int npc_model;
int coin_model;
int frisbee_model;
int game_mode;
int clear_frame_count;

Camera camera;
Ground ground;
Player player;
Npc npc;
std::vector<Coin *> coins;
Frisbee frisbee;
UI ui;

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
	coin_model = MV1LoadModel("SampleData/Model/ImageToStl.com_coin.mv1");
	frisbee_model = MV1LoadModel("SampleData/Model/10505_Frisbee_v3_L3.mv1");
	game_mode = GAME_TITLE;
	clear_frame_count = 3 * FRAME_PER_SECOND;

	SetMouseDispFlag(TRUE);
	camera.Init();
	ground.Init(ground_model);
	player.Init(player_model);
	npc.Init(npc_model);
	for (int i = 0; i < COIN_NUM; i++)
		coins.push_back(new Coin(coin_model));
	frisbee.Init(frisbee_model);
	ui.Init();
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
	ground.Update();
	Vector3 hit_coin_pos;
	int coin_count = 0;
	for (auto &coin : coins)
	{
		if (coin)
			coin_count++;
	}
	switch (game_mode)
	{
	case GAME_TITLE:
		npc.Update();
		if (ui.CheckHitStart())
		{
			game_mode = GAME_PRE_COUNT;
		}
		break;
	case GAME_PRE_COUNT:
		player.Update();
		SetMousePoint(SCREEN_W / 2, SCREEN_H / 2);
		for (auto &coin : coins)
		{
			if (coin)
			{
				coin->Update();
			}
		}
		if (ui.GetPreCount() <= 0)
		{
			game_mode = GAME_START;
		}
		break;
	case GAME_START:
		player.Update();
		SetMousePoint(SCREEN_W / 2, SCREEN_H / 2);

		for (auto &coin : coins)
		{
			if (coin)
			{
				coin->Update();
				if (frisbee.CheckCoinHit(coin))
				{
					ui.ScoreAdd(500);
					hit_coin_pos = coin->m_pos;
					delete coin;
					coin = nullptr;
				}
				if (frisbee.CheckCatch(player.m_pos, player.m_radius))
				{
					ui.ScoreAdd(500);
				}
			}
		}
		frisbee.Update(player.m_pos, player.m_rot, hit_coin_pos);
		if (ui.GetTime() <= 0 || coin_count == 0)
		{
			game_mode = GAME_CLEAR;
		}
		break;
	case GAME_CLEAR:
		clear_frame_count--;
		if (clear_frame_count <= 0)
		{
			game_mode = GAME_RESULT;
		}
		break;
	case GAME_RESULT:
		break;
	}

	camera.Update(player.m_pos, player.m_rot);
	ui.Update(coin_count, game_mode);
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void GameRender()
{
	ground.Render();
	int coin_count = 0;
	for (auto &coin : coins)
	{
		if (coin)
			coin_count++;
	}
	switch (game_mode)
	{
	case GAME_TITLE:
		npc.Render();
		break;
	case GAME_PRE_COUNT:
		SetMouseDispFlag(false);
		for (auto &coin : coins)
		{
			if (coin)
				coin->Render();
		}
		player.Render();
		break;
	case GAME_START:
		SetMouseDispFlag(false);
		for (auto &coin : coins)
		{
			if (coin)
				coin->Render();
		}
		player.Render();
		frisbee.Render();
		break;
	case GAME_CLEAR:
		break;
	case GAME_RESULT:
		SetMouseDispFlag(true);
		break;
	}
	camera.Render();
	ui.Render(coin_count, game_mode);
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
