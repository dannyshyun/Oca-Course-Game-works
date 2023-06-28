#pragma once
#include <stdint.h>

class ItemCard : public CardBase
{  
public:
    ItemCard(int image, uint32_t value, uint32_t part);
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

protected:
};
