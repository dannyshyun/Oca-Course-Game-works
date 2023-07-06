#include "json.h"
#include "Main.h"
#include "Game.h"
#include "Hit.h"

#include "Camera.h"
#include "Ground.h"
#include "Player.h"
#include "Npc.h"
#include "UI.h"

#include "Base.h"
#include "CardBase.h"
#include "ActionCard.h"
#include "EnvironmentCard.h"
#include "ItemCard.h"
#include "ChanceCard.h"
#include "CurseCard.h"
#include "HpPlusCard.h"
#include "Deck.h"
#include <memory>
#include <vector>
//	モデルデータ

//	クラス宣言
IMGcontroller           IMGctrl;
int                     Turn;
std::unique_ptr<Player> player = std::make_unique<Player>( 0 );
std::unique_ptr<Npc>    npc    = std::make_unique<Npc>( 0 );
std::unique_ptr<UI>     ui     = std::make_unique<UI>( 0 );
//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void GameInit()
{
    IMGctrl.Init();
    Turn = LOAD_TURN;
    npc->Init();
    player->Init();
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
    npc->Update();
    player->Update();
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void GameRender()
{
    npc->Render();
    player->Render();
    ui->Render();
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void GameExit()
{
}
