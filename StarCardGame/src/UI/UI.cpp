#include "Main.h"
#include "Game.h"
#include "Base.h"
#include "UI.h"

UI::UI( int image ) : Base( image )
{
}
void UI::Init()
{
}

void UI::Update()
{
}

void UI::Render()
{

    switch( Turn )
    {
        case LOAD_TURN : break;
        case SHUFFLE_TURN : break;
        case DEAL_TURN : break;
        case MOVE_TURN : DrawMove(); break;
        case PLAYER_ATTACK_TURN : break;
        case PLAYER_DEFENSE_TURN : break;
        case NPC_ATTACK_TURN : break;
        case NPC_DEFESE_TURN : break;
        case RESULT_TURN : break;
        case TURN_MAX : break;
        default :;
    }
}

void UI::Release()
{
}

void UI::DrawMove()
{
    ChangeFontType( DX_FONTTYPE_EDGE );
    SetFontSize( 36 );
    const uint16_t height = 30;
    std::string    name   = "MOVE TURN";
    uint16_t       n_x    = ( SCREEN_W - GetDrawStringWidth( (const TCHAR*)name.c_str(), -1 ) ) * 0.5;
    SetDrawBlendMode( DX_BLENDMODE_ALPHA, 128 );
    DrawBox( 0, SCREEN_H / 2 - height, SCREEN_W, SCREEN_H / 2 + height, WHITE, true );
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND, -1 );
    DrawString( n_x, SCREEN_H / 2 - 20, (const TCHAR*)name.c_str(), WHITE );
    SetFontSize( 20 );
}
