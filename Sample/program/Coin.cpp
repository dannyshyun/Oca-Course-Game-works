#include "Main.h"
#include "Game.h"
#include "Coin.h"

Coin::Coin(int model, Vector3 pos)
{
	Init(model, pos);
}

Coin::~Coin()
{
}

void Coin::Init(int model, Vector3 pos)
{
	m_model = model;

	m_pos.set(pos);
	m_rot.set(90.f, 0.f, 0.f);
	m_radius = 1.f;
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
	// DrawSphere3D(VGet(m_pos.x, m_pos.y, m_pos.z), m_radius, 32, RED, GREEN, false);
}

void Coin::Exit()
{
}
