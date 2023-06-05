#pragma once
enum StarPart
{
    STAR_HEAD = 0,
    STAR_RIGHT_HAND,
    STAR_LEFT_HAND,
    STAR_RIGHT_LEG,
    STAR_LEFT_HAND
};

class CardBase : public Base
{
  public:
      CardBase();
      ~CardBase();
      virtual void Init() override;
      virtual void Update() override;
      virtual void Render() override;
      virtual void Release() override;
      virtual unsigned int GetCardVal() const;

  protected: 
      unsigned int valume_ = 0;
      unsigned int part_ = 0;
};