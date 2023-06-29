#include "Main.h"
#include "Game.h"
#include "Base.h"
#include "CardBase.h"
CardBase::CardBase( int image, uint32_t value, uint32_t part ) :
    Base( image ), value( value ), part( part ), is_select( false )
{
    GetGraphSize( image, &size.x, &size.y );
}

CardBase::~CardBase()
{
}

void CardBase::Init()
{
}

void CardBase::Update()
{
    bool is_player = pos.y > SCREEN_H * 0.5;
    
    pos.y = is_select                            //
                ? is_player                      //!< true
                      ? SCREEN_H - 100           //!< true
                      : SCREEN_H + 100           //!< false
                                                 //
                : is_touch                       //!< false
                      ? SCREEN_H - size.y * 0.5  //!< true
                      : SCREEN_H;                //!< false
}

void CardBase::Render( bool is_show )
{
    DrawRotaGraph( pos.x,
                   pos.y,
                   1,
                   0,
                   is_show ? image : IMGctrl.GetCardIMGdata( "back" ),
                   true );
}

void CardBase::Release()
{
}

unsigned int CardBase::GetCardVal() const
{
    return this->value;
}

uint32_t CardBase::GetImage() const
{
    return this->image;
}
