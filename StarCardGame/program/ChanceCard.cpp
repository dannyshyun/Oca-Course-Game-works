#include "Base.h"
#include "CardBase.h"
#include "ItemCard.h"
#include "ChanceCard.h"

ChanceCard::ChanceCard(int image, uint32_t value, uint32_t part):
ItemCard(image, value, part)
{
    
}
void ChanceCard::Init()
{
    ItemCard::Init();
}

void ChanceCard::Update()
{
    ItemCard::Update();
}

void ChanceCard::Render()
{
    ItemCard::Render();
}

void ChanceCard::Release()
{
    ItemCard::Release();
}

