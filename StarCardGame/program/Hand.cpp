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
    for ( auto& card: *hand ) { card->Render(); }
}

void Hand::Release()
{
}

Cards Hand::Fold( Cards cards )
{
    return cards;
}

void Hand::Draw( Cards cards ,bool is_player)
{
    uint16_t i = 0;
    uint16_t size = cards.size();
    for ( auto& card: cards ) {
        uint16_t offset = 80;
        uint16_t x = SCREEN_W / 2 + ( i - size / 2 ) * offset;
        uint16_t y = is_player ? SCREEN_H - 100 : 100;
        card->pos = Vector2( x, y );
        hand->push_back( card );
        i++;
    }
}

uint16_t Hand::GetHandNum()
{
    return hand->size();
}
