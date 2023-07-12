#pragma once
#include <stdint.h>
#include <vector>
#include <memory>

#include "BaseClass/Base.h"

enum StarPart
{
    STAR_HEAD = 0,
    STAR_RIGHT_HAND,
    STAR_LEFT_HAND,
    STAR_RIGHT_LEG,
    STAR_LEFT_LEG,

    STAR_NUM_MAX
};

class CardBase : public Base
{
public:
    CardBase( int image, uint32_t value, uint32_t part );
    ~CardBase();
    virtual void         Init() override;
    virtual void         Update() override;
    virtual void         Render( bool is_show );
    virtual void         Release() override;
    virtual unsigned int GetCardVal() const;
    virtual uint32_t     GetImage() const;

    bool is_select = false;
    bool is_touch  = false;

protected:
    uint32_t value = 0;
    uint32_t part  = 0;
};
typedef std::vector<std::shared_ptr<CardBase>> Cards;
typedef std::unique_ptr<Cards>                 ptr_cards;
