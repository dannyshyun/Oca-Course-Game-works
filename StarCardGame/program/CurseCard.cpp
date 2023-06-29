#include "Base.h"
#include "CardBase.h"
#include "ItemCard.h"
#include "CurseCard.h"
CurseCard::CurseCard( int image, uint32_t value, uint32_t part ) :
    ItemCard( image, value, part )
{
}
void CurseCard::Init()
{
    ItemCard::Init();
}

void CurseCard::Update()
{
    ItemCard::Update();
}

void CurseCard::Render()
{
    ItemCard::Render();
}

void CurseCard::Release()
{
    ItemCard::Release();
}
