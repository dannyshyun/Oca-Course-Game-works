#include "Main.h"
#include "Game.h"
#include "Random.h"
#include "Base.h"
#include "Player.h"
#include "Npc.h"



Npc::Npc( int image ) : Player( image )
{
    deck = std::make_unique<Deck>( 0 );
    hand = std::make_unique<Hand>( 0 );
}
//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void Npc::Init()
{
    deck->Init();
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void Npc::Update()
{
    switch ( Turn )
    {
        case LOAD_TURN : deck->Load(); break;

        case SHUFFLE_TURN : deck->Shuffle(); break;

        case DEAL_TURN :

            if ( hand->GetHandNum() < HAND_MAX )
            {
                hand->Init();
                hand->Draw( deck->Deal( HAND_MAX - hand->GetHandNum() ),false );
            }
            break;
    }
    deck->Update();
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void Npc::Render()
{
    deck->Render(false);
    hand->Render(false);
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void Npc::Release()
{
}

void Npc::SelectCard( CardBase card )
{
}
