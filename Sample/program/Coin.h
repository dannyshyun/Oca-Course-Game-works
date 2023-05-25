#pragma once
#include "Base.h"

class Coin : public Base
{
public:

	Coin(int model, Vector3 pos);
	~Coin();

	void Init(int model, Vector3 pos);		//	‰Šú‰»ˆ—
	void Update();		//	XVˆ—
	void Render();		//	•`‰æˆ—
	void Exit();		//	I—¹ˆ—

private:

};
