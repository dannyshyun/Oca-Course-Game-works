#pragma once
#include "Base.h"
class Deck : public Base
{
public:
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;

private:
};