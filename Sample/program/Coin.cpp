#include "Main.h"
#include "Game.h"
#include "Coin.h"

void Coin::Init(int model)
{
	m_model = model;

	m_pos.set(0.f, 4.5f, 0.f);
	m_rot.set(90.f, 0.f, 0.f);
	m_radius = 0.5f;
}

void Coin::Update()
{
	m_rot.y ++;
}

void Coin::Render()
{
	MV1SetPosition(m_model, VGet(m_pos.x, m_pos.y, m_pos.z));
	MV1SetRotationXYZ(m_model, VGet(TO_RADIAN(m_rot.x), TO_RADIAN(m_rot.y),TO_RADIAN(m_rot.z)));
	MV1DrawModel(m_model);
}

void Coin::Exit()
{
}
