#include "Base.h"
#include "CardBase.h"
#include "ActionCard.h"

ActionCard::ActionCard()
{
  Init();
}

ActionCard::~ActionCard()
{
}

void ActionCard::Init()
{
}

void ActionCard::Update()
{
}

void ActionCard::Render()
{
}

void ActionCard::Release()
{
}

unsigned int ActionCard::GetType() const
{
  return type;
}
