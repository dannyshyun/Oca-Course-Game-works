#pragma once
class HpPlusCard : public ItemCard
{
public:
    HpPlusCard( int image, uint32_t value, uint32_t part );
    void Init() override;
    void Update() override;
    void Render(bool is_show) override;
    void Release() override;

private:
};