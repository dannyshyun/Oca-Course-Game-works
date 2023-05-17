#pragma once
#include "Vector2.h"
class MouseCtrl
{
public:
	void Init();
	void Update();
	void Render();
	void Exit();

	void SetPos(float x, float y);
	Vector2 GetPos() const;
private:
	Vector2 m_pos;
};


