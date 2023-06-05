#pragma once
#include "CardBase.h"

class ItemCard : public CardBase
{  
public:
    ItemCard();
    ~ItemCard();
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

private:
};
