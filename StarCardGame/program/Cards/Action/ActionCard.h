#pragma once
#include <string>

enum ActionSuit
{
    ACTION_MOVE = 0,
    ACTION_SWORD,
    ACTION_GUN,
    ACTION_DEFENSE,

    ACTION_MAX
};

class ActionCard : public CardBase
{
    public:
    ActionCard( int image, uint32_t value, uint32_t part, std::string suit );
        ~ActionCard();
        void Init() override;
        void Update() override;
        void Render(bool is_show) override;
        void Release() override;

        std::string GetSuit() const;
        
    protected:
        std::string suit = 0;
}; 