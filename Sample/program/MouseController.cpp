#include "Main.h"
#include "Game.h"
#include "MouseController.h"

void MouseCtrl::Init()
{
	SetMouseDispFlag(FALSE);
	SetMousePoint(SCREEN_W / 2, SCREEN_H / 2);
}

void MouseCtrl::Update()
{

}

void MouseCtrl::SetPos(float x, float y)
{
	SetMousePoint(x, y);
}

Vector2 MouseCtrl::GetPos() const
{
	return { GetMouseX(), GetMouseY() };
}
