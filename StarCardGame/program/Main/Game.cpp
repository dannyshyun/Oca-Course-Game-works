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
//	���f���f�[�^

//	�N���X�錾
IMGcontroller           IMGctrl;
int                     Turn;
std::unique_ptr<Player> player = std::make_unique<Player>( 0 );
std::unique_ptr<Npc>    npc    = std::make_unique<Npc>( 0 );
std::unique_ptr<UI>     ui     = std::make_unique<UI>( 0 );
//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void GameInit()
{
    IMGctrl.Init();
    Turn = LOAD_TURN;
    npc->Init();
    player->Init();
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void GameUpdate()
{
    npc->Update();
    player->Update();
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void GameRender()
{
    npc->Render();
    player->Render();
    ui->Render();
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void GameExit()
{
}
