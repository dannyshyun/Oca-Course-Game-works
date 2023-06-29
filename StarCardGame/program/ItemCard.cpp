#include "Base.h"
#include "CardBase.h"
#include "ItemCard.h"


ItemCard::ItemCard(int image, uint32_t value, uint32_t part) :CardBase(image, value, part)
{
    
}
void ItemCard::Init()
{
    CardBase::Init();
}

void ItemCard::Update()
{
    CardBase::Update();
}

void ItemCard::Render()
{
    CardBase::Render();
}

void ItemCard::Release()
{
    CardBase::Release();
}

