#pragma once

class EventCard : public CardBase
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

private:
};