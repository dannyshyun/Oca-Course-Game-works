#include "Base.h"
#include "CardBase.h"
#include "ActionCard.h"

ActionCard::ActionCard( int         image,
                        uint32_t    value,
                        uint32_t    part,
                        std::string suit ) :
    CardBase( image, value, part ), suit( suit )
{
}

ActionCard::~ActionCard()
{
}

void ActionCard::Init()
{
    CardBase::Init();
}

void ActionCard::Update()
{
    CardBase::Update();
}

void ActionCard::Render(bool is_show)
{
    CardBase::Render(is_show);
}

void ActionCard::Release()
{
    CardBase::Release();
}

std::string ActionCard::GetSuit() const
{
    return suit;
}
