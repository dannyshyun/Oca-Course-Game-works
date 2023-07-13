﻿#include "WinMain.h"
#include "Game/GameMain.h"
#include "BaseClass/Base.h"
#include "CardBase.h"

CardBase::CardBase( int image, u32 value, u32 part ) :
    ::Base( image ), value( value ), part( part ), is_select( false )
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
    bool           is_player = pos.y > WINDOW_H * 0.5;
    const uint16_t offset( 200 );

    pos.y = is_select                           //
                ? is_player                     //!< true
                      ? WINDOW_H - offset       //!< true
                      : WINDOW_H + offset       //!< false
                                                //
                : is_touch                      //!< false
                      ? WINDOW_H - size.y * 0.5 //!< true
                      : WINDOW_H;               //!< false
}

void CardBase::Render( bool is_show )
{
    DrawRotaGraph( pos.x, pos.y, 1, 0, is_show ? image : IMGctrl.GetCardIMGdata( "back" ), true );
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
