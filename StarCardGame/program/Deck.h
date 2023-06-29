#pragma once
#include "CardBase.h"

class Deck : public Base
{
public:
    Deck( int image );
    ~Deck();
    void Init() override;
    void Update() override;
    void Render(bool is_player);
    void Release() override;

    void  Revoke( Cards cards );
    bool  Load();
    bool  Shuffle();
    Cards Deal( uint16_t num );

    uint16_t GetCardNum() const;

private:
    void      LoadCardsIMG();
    ptr_cards deck;
    // the number of card in deck
    uint16_t  card_num;
};