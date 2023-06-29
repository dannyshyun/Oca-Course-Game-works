#include "Main.h"
#include "Base.h"
#include "CardBase.h"
CardBase::CardBase( int image, uint32_t value, uint32_t part ) :
    Base( image ), value( value ), part( part ), is_select(false)
{
}

CardBase::~CardBase()
{
}

void CardBase::Init()
{
}

void CardBase::Update()
{
}

void CardBase::Render()
{
    DrawRotaGraph( pos.x, pos.y, 1, 0, image, true );
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
