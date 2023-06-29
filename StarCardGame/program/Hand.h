#pragma once
#include <stdint.h>
#include "CardBase.h"
#define HAND_MAX 7
class Hand : Base
{
public:
    Hand( int image );
    void Init() override;
    void Update() override;
    void Render(bool is_player);
    void Release() override;

    Cards Fold( Cards cards );
    void  Draw(Cards cards, bool is_player);
    uint16_t  GetHandNum();

private:
    ptr_cards hand;
     
};