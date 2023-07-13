//---------------------------------------------------------------------------
//!	@file	GameMain.cpp
//! @brief	ゲームメイン
//---------------------------------------------------------------------------
#include "GameMain.h"
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
#include "GameObjects/Deck.h"

IMGcontroller IMGctrl;
int           Turn;
//---------------------------------------------------------------------------------
//!	初期化
//---------------------------------------------------------------------------------
bool GameInit()
{
    return true;
}

//---------------------------------------------------------------------------------
//!	更新
//---------------------------------------------------------------------------------
void GameUpdate()
{
}

//---------------------------------------------------------------------------------
//!	描画
//---------------------------------------------------------------------------------
void GameDraw()
{
}

//---------------------------------------------------------------------------------
//!	終了
//---------------------------------------------------------------------------------
void GameExit()
{
}
