#pragma once
class HandDropCard : public ItemCard
{
public:
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;

private:
};