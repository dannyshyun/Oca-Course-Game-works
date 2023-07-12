#include "Main.h"
#include "Game.h"
#include "GameSystem//Hit.h"

#include "Characters/Player.h"
#include "Characters/Npc.h"
#include "UI/UI.h"

#include "BaseClass/Base.h"
#include "Cards/CardBase.h"
#include "Cards/Action/ActionCard.h"
#include "Cards/Environment/EnvironmentCard.h"
#include "Cards/Item/ItemCard.h"
#include "Cards/Item/ChanceCard.h"
#include "Cards/Item/CurseCard.h"
#include "Cards/Item/HpPlusCard.h"
#include "GameObjects//Deck.h"
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
