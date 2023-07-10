#include <BaseClass/Base.h>
#include <Cards/CardBase.h>
#include "ItemCard.h"
#include "ChanceCard.h"

ChanceCard::ChanceCard( int image, uint32_t value, uint32_t part ) : ItemCard( image, value, part )
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

void ChanceCard::Render( bool is_show )
{
    ItemCard::Render( is_show );
}

void ChanceCard::Release()
{
    ItemCard::Release();
}
