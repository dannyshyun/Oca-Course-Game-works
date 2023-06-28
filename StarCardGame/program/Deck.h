#pragma once
#include "CardBase.h"

class Deck : public Base
{
public:
    Deck( int image );
    ~Deck();
    void Init() override;
    void Update(uint16_t turn);
    void Render() override;
    void Release() override;

    Cards Deal( uint16_t num );
    void  Revoke( Cards cards );
    void  Shuffle();

private:
    void      LoadCardsIMG();
    ptr_cards deck;
    // the number of card in deck
    uint16_t  card_num;
};