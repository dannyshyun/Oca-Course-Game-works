#include "Main.h"
#include "Game.h"
#include "Base.h"
#include "Player.h"

Player::Player( int image ) : Base( image )
{
    deck = std::make_unique<Deck>( 0 );
    hand = std::make_unique<Hand>( 0 );
}
//---------------------------------------------------------------------------------
//	‰Šú‰»ˆ—
//---------------------------------------------------------------------------------
void Player::Init()
{
    deck->Init();
}
//---------------------------------------------------------------------------------
//	XVˆ—
//---------------------------------------------------------------------------------
void Player::Update()
{
    switch ( Turn )
    {
        case LOAD_TURN :
            if ( deck->LOAD() )
                Turn = SHUFFLE_TURN;
            break;

        case SHUFFLE_TURN :
            if ( deck->Shuffle() )
                Turn = DEAL_TURN;
            break;

        case DEAL_TURN :

            if ( hand->GetHandNum() < HAND_MAX )
            {
                hand->Init();
                hand->Draw( deck->Deal( HAND_MAX - hand->GetHandNum() ) );
            }
            break;

        case MOVE_TURN : break;

        case PLAYER_ATTACK_TURN : break;

        case PLAYER_DEFENSE_TURN : break;

        case NPC_ATTACK_TURN : break;

        case NPC_DEFESE_TURN : break;

        case RESULT_TURN : break;

        case TURN_MAX : break;

        default :;
    }
    deck->Update();
}
//---------------------------------------------------------------------------------
//	•`‰æˆ—
//---------------------------------------------------------------------------------
void Player::Render()
{
    deck->Render();
    hand->Render( true );
}
//---------------------------------------------------------------------------------
//	I—¹ˆ—
//---------------------------------------------------------------------------------
void Player::Release()
{
}

void Player::SelectCard( CardBase card )
{
}
