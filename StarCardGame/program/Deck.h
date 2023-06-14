#pragma once
#include "CardBase.h"
#include <vector>
#include <memory>
class Deck : public Base
{
public:
    Deck();
    ~Deck();
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;

    std::vector<CardBase *>* Deal(int num);
    void Revoke(int num);

private:
    std::vector<CardBase *>* deck;
    std::unique_ptr<vector<CardBase *>> deck;
};