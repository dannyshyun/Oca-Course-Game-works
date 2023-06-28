#include "Base.h"
#include "CardBase.h"
#include "ActionCard.h"

ActionCard::ActionCard( int         image,
                        uint32_t    value,
                        uint32_t    part,
                        std::string suit ) :
    CardBase( image, value, part ) , suit( suit )
{
}

ActionCard::~ActionCard()
{
}

void ActionCard::Init()
{
}

void ActionCard::Update()
{
}

void ActionCard::Render()
{
}

void ActionCard::Release()
{
}

std::string ActionCard::GetSuit() const
{
    return suit;
}
