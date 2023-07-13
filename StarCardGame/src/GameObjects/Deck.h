#pragma once
#include "Cards/CardBase.h"

class Deck : public Base
{
public:
    Deck( int image );
    ~Deck();
    void Init() override;
    void Update() override;
    void Render( bool is_player );
    void Release() override;

    // revoke cards which are folded
    void Revoke( Cards cards );
    // load turn
    bool Load();
    // shuffle turn
    bool Shuffle();

    // deal cards from deck
    Cards Deal( uint16_t num );
    // get card num from deck
    uint16_t GetCardNum() const;

private:
    Card<CardBase> NewActionCard( std::string suit, u32 value );
    Card<CardBase> NewChanceCard( std::string suit, u32 value );
    Card<CardBase> NewHpPlusCard( std::string suit, u32 value );
    Card<CardBase> NewCurseCard( std::string suit, u32 value );
    void           LoadCardsIMG();
    // card container
    ptr_cards deck;
    // the number of card to render
    uint16_t card_num;
};
