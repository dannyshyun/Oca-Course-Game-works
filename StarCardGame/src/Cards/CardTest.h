﻿#pragma once
#include <System/Scene.h>

USING_PTR( CardTest );
class CardTest : public Object
{
public:
    BP_OBJECT_TYPE( CardTest, Object );
    static CardTestPtr Create( float3 pos = { 0.f, 0.f, 0.f } );
    virtual bool       Init() override;
    virtual void       Update() override;
    virtual void       Render( bool is_show );
    virtual void       GUI() override;
    virtual void       Exit() override;
    virtual u32        GetCardVal() const;
    virtual u32        GetImage() const;

    bool is_player = true;
    bool is_select = false;
    bool is_touch  = false;

protected:
    int    image = -1;
    u32    value = 0;
    u32    part  = 0;
    float2 image_size{ 0.f, 0.f };
};