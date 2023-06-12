#pragma once


class ItemCard : public CardBase
{  
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

protected:
};
