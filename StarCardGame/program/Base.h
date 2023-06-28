#pragma once
#include "Vector2.h"
#include "Vector3.h"

//---------------------------------------------------------------------------------
//	Šî–{ƒNƒ‰ƒX
//---------------------------------------------------------------------------------
class Base
{
public:
    Base(int image);
    virtual void Init();
    virtual void Update();
    virtual void Render();
    virtual void Release();

    Vector2 pos;
    Vector2 rot;
    float   radius;
protected:
    int     model;
    int     image;
};
