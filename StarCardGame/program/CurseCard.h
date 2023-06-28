#pragma once
#include <stdint.h>
class CurseCard : public ItemCard
{
public:
    CurseCard( int image, uint32_t value, uint32_t part );
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;

private:
};