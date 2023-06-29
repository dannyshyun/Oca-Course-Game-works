#include "Main.h"
#include "Game.h"
#include "Base.h"
#include "Hand.h"
Hand::Hand( int image ) : Base( image )
{
    hand = std::make_unique<Cards>();
}

void Hand::Init()
{
}

void Hand::Update()
{
}

void Hand::Render( bool is_player )
{

    uint16_t i = 0;
    for ( auto& card: *hand )
    {
        uint16_t x = SCREEN_W / 2 + ( i - (uint16_t)hand->size() / 2 ) * 100;
        uint16_t y = is_player ? SCREEN_H - 100 : 100;
        DrawRotaGraph( x, y, 1.5, 0, card->GetImage(), true );
        i++;
    }
}

void Hand::Release()
{
}

Cards Hand::Fold( Cards cards )
{
    return cards;
}

void Hand::Draw( Cards cards )
{
    for ( auto& card: cards ) {
        card->pos = Vector2( 60, 40 );
        hand->push_back( card );
    }
}

uint16_t Hand::GetHandNum()
{
    return hand->size();
}
