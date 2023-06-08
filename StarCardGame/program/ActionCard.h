#pragma once

enum ActionType
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
        ActionCard();
        ~ActionCard();
        void Init() override;
        void Update() override;
        void Render() override;
        void Release() override;

        unsigned int GetType() const;
        
    protected:
        unsigned int type = 0;
}; 