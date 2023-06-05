#pragma once
#include "Vector2.h"
#include "Vector3.h"

//---------------------------------------------------------------------------------
//	Šî–{ƒNƒ‰ƒX
//---------------------------------------------------------------------------------
class Base
{
public:
	Base();
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

protected:
	Vector2	pos_;
	Vector2	rot_;
	int		model_;
	float	radius_;
};
