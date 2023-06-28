#include "json.h"
#include "Main.h"
#include "Game.h"
#include "Hit.h"

#include "Camera.h"
#include "Ground.h"
#include "Player.h"
#include "Npc.h"

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
//	���f���f�[�^

//	�N���X�錾
uint16_t                turn;
std::unique_ptr<Player> player = std::make_unique<Player>( 0 );
std::unique_ptr<Npc>    npc    = std::make_unique<Npc>( 0 );
//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void GameInit()
{
    IMGctrl.Init();
    turn = LOAD_TURN;
    player->Init();
    npc->Init();
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void GameUpdate()
{
    player->Update( turn );
    npc->Update( turn );
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void GameRender()
{
    player->Render();
    // npc->Render();
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void GameExit()
{
}
